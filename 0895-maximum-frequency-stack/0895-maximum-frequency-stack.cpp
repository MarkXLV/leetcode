class FreqStack {
private:
    unordered_map<int, int> cnt;
    vector<int> stack;

public:
    FreqStack() {}

    void push(int val) {
        stack.push_back(val);
        cnt[val]++;
    }

    int pop() {
        int maxCnt = 0;
        for (auto& [_, frequency] : cnt) {
            maxCnt = max(maxCnt, frequency);
        }
        int i = stack.size() - 1;
        while (cnt[stack[i]] != maxCnt) {
            i--;
        }
        int val = stack[i];
        stack.erase(stack.begin() + i);
        cnt[val]--;
        return val;
    }
};