class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int,unordered_map<int,int>>dp;
        // buy
        dp[1][1]=-prices[0];
        // rest
        dp[1][0]=0;
        // sold
        dp[1][2]=0;
        int n=prices.size();
        for(int i=2;i<=prices.size();i++)
        {
            // sold
            dp[i][2]=dp[i-1][1]+prices[i-1];
            // buy
            dp[i][1]=max(dp[i-1][0]-prices[i-1],dp[i-1][1]);
            // rest
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        return max(dp[n][2],dp[n][0]);
    }
};