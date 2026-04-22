class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][101];

    int solve(int i, int M, vector<int>& piles) {
        if (i >= n) return 0;

        if (2 * M >= n - i) {
            return suffix[i]; // take all remaining
        }

        if (dp[i][M] != -1) return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            int opponent = solve(i + X, max(M, X), piles);
            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.resize(n);
        memset(dp, -1, sizeof(dp));

        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        return solve(0, 1, piles);
    }
};