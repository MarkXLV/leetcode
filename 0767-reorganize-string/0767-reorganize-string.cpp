class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        auto cmp = [](pair<int, char> a, pair<int, char> b) { return a.first < b.first; };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> maxHeap(cmp);
        
        for (auto& [ch, count] : freq) {
            if (count > (s.length() + 1) / 2) return "";
            maxHeap.push({count, ch});
        }

        string result = "";
        while (maxHeap.size() > 1) {
            auto [count1, char1] = maxHeap.top(); maxHeap.pop();
            auto [count2, char2] = maxHeap.top(); maxHeap.pop();

            result += char1;
            result += char2;

            if (--count1 > 0) maxHeap.push({count1, char1});
            if (--count2 > 0) maxHeap.push({count2, char2});
        }

        if (!maxHeap.empty()) {
            result += maxHeap.top().second;
        }

        return result;
    }
};