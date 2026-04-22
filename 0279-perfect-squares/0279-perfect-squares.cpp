class Solution {
public:
    int numSquares(int n) {
        vector<int>canditates;
        for(int i=1;i*i<=n;i++)
        {
            canditates.push_back(i*i);
        }
        vector<unsigned long long>dp(n+1,INT_MAX);
        dp[0]=0;
        for(auto x:canditates)
        {
            for(int i=1;i<=n;i++)
            {
                if(i-x>=0)
                {
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        return dp[n];
    }
};