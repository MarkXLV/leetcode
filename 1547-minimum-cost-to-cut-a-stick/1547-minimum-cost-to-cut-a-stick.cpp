class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        std::vector<std::vector<int>> dp(c, std::vector<int>(c, 0));

        for (int l = 2; l < c; ++l) {
            for (int i = 0; i < c - l; ++i) {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }

        return dp[0][c - 1];
    }
};