#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;

    // key -> iterator in list
    unordered_map<int, list<pair<int,int>>::iterator> cache;

    // list stores {key, value}, most recent at front
    list<pair<int,int>> dll;

    // 🔥 move node to front (most recently used)
    void makeRecent(int key) {
        auto it = cache[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        makeRecent(key);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // key exists → update + move to front
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            makeRecent(key);
            return;
        }

        // cache full → remove LRU (back)
        if (cache.size() == capacity) {
            auto last = dll.back();
            cache.erase(last.first);
            dll.pop_back();
        }

        // insert new key at front
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};