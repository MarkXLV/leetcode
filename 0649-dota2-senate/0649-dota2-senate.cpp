class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQueue, direQueue;
        int n = senate.size();

        // Initialize queues with indices of 'R' and 'D'
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiantQueue.push(i);
            else
                direQueue.push(i);
        }

        // Simulate the voting process
        while (!radiantQueue.empty() && !direQueue.empty()) {
            int radiantIndex = radiantQueue.front(); radiantQueue.pop();
            int direIndex = direQueue.front(); direQueue.pop();

            if (radiantIndex < direIndex)
                radiantQueue.push(radiantIndex + n);
            else
                direQueue.push(direIndex + n);
        }

        return radiantQueue.empty() ? "Dire" : "Radiant";
    }
};