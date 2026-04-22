class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)return 1;
        vector<unsigned long long>dp(n+1,1);
        // dp[2]=1;
        // dp[3]=2;    
        // dp[4]=4;
        // dp[5]=6;
        // dp[6]=8;
        for(unsigned long long i=3;i<=n;i++)
        {
            for(unsigned long long j=1;j<i;j++)
            {
                unsigned long long one=max(dp[j],j);
                unsigned long long two=max(dp[i-j],i-j);
                dp[i]=max(dp[i],one*two);
            }
        }
        return dp[n];

    }
};