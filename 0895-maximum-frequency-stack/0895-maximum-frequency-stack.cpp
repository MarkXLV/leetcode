class FreqStack {
private:
    priority_queue<vector<int>> heap; // {frequency, index, value}
    unordered_map<int, int> cnt;
    int index;

public:
    FreqStack() : index(0) {}

    void push(int val) {
        cnt[val]++;
        heap.push({cnt[val], index++, val});
    }

    int pop() {
        auto top = heap.top();
        heap.pop();
        int val = top[2];
        cnt[val]--;
        return val;
    }
};