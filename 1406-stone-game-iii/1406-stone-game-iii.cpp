class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;  // Base case: no stones left
        
        for (int i = n - 1; i >= 0; --i) {
            int score = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                score += stoneValue[i + j];
                dp[i] = max(dp[i], score - dp[i + j + 1]);
            }
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};