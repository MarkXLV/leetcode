class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int farthest = 0;

        while (!q.empty()) {
            int i = q.front(); q.pop();

            for (int j = max(i + minJump, farthest + 1); j <= min(i + maxJump, n - 1); ++j) {
                if (s[j] == '0' && !visited[j]) {
                    if (j == n - 1) return true;
                    q.push(j);
                    visited[j] = true;
                }
            }
            farthest = min(i + maxJump, n - 1);
        }

        return false;
    }
};
