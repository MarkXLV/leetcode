class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int total=0;
        for(auto x:stones)total+=x;
        int sum=total/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)
        dp[i][0]=true;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j-stones[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        for(int i=sum;i>=0;i--)
        {
            if(dp[n][i])
            {
                return total-2*i;
            }
        }
        return 0;

    }
};