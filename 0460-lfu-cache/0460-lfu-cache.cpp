#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int capacity, minFreq;

    // key -> {freq, iterator in freq list}
    unordered_map<int, pair<int, list<pair<int,int>>::iterator>> keyTable;

    // freq -> list of {key, value}
    unordered_map<int, list<pair<int,int>>> freqTable;

    // 🔥 Helper: update frequency
    void updateFreq(int key) {
        auto &[freq, iter] = keyTable[key];
        int value = iter->second;

        // remove from current freq list
        freqTable[freq].erase(iter);

        // clean up if needed
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // move to next freq
        freq++;
        freqTable[freq].push_back({key, value});
        keyTable[key] = {freq, --freqTable[freq].end()};
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyTable.find(key) == keyTable.end()) return -1;

        updateFreq(key);
        return keyTable[key].second->second;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // key exists → update + freq++
        if (keyTable.find(key) != keyTable.end()) {
            keyTable[key].second->second = value;
            updateFreq(key);
            return;
        }

        // cache full → evict LFU
        if (keyTable.size() == capacity) {
            auto &listRef = freqTable[minFreq];
            int keyToRemove = listRef.front().first;

            listRef.pop_front();
            if (listRef.empty()) freqTable.erase(minFreq);

            keyTable.erase(keyToRemove);
        }

        // insert new key
        minFreq = 1;
        freqTable[1].push_back({key, value});
        keyTable[key] = {1, --freqTable[1].end()};
    }
};