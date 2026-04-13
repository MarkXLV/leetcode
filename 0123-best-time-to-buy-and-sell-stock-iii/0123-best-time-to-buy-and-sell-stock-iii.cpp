class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit(2,prices);
        long long firstbuy=INT_MAX;  
        // 3 3 3 0 0 0 0 0
        long long firstsell=INT_MIN; 
        // 0 0 2 2 2 3 3 4
        long long secondbuy=INT_MAX; 
        // 3 3 3 -2 -2 -2 -2 -2
        long long secondsell=INT_MIN; 
        // 0 0 2 2 2 5 5 6
        long long ans=0;
        for(int i=0;i<prices.size();i++)
        {
            firstbuy=min(firstbuy,1ll*prices[i]);
            firstsell=max(firstsell,1ll*prices[i]-firstbuy);
            secondbuy=min(secondbuy,1ll*prices[i]-firstsell);
            secondsell=max(secondsell,1ll*prices[i]-secondbuy);
            ans=max(ans,secondsell);
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++)
        {
            int buy=-prices[0];
            for(int j=1;j<n;j++)
            {
                dp[i][j]=max(dp[i][j-1],prices[j]+buy);
                buy=max(buy,dp[i-1][j-1]-prices[j]);
            }
        }
        return dp[k][n-1];
    }
    
};