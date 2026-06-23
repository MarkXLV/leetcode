class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int const MOD=1e9+7;
        int m=r-l+1;
        vector<int>dp0(m+1,0),dp1(m+1,0);
        vector<int>sum0(m+1,0),sum1(m+1,0);

        for(int i=1;i<=m;i++)
        {
            dp0[i]=dp1[i]=1;
        }

        for(int i=1;i<n;i++)
        {
            // prefix sum optimization for dp
            for(int j=1;j<=m;j++)
            {
                sum0[j]=(sum0[j-1]+dp0[j])%MOD;
                sum1[j]=(sum1[j-1]+dp1[j])%MOD;
            }
            for(int j=1;j<=m;j++)
            {
                dp0[j]=(sum1[m]-sum1[j]+MOD)%MOD;
                dp1[j]=sum0[j-1]%MOD;
            }
        }

        auto op=[](int acc,int x){return (acc+x)%MOD;};
        int ans1=reduce(dp0.begin(),dp0.end(),0,op);
        int ans2=reduce(dp0.begin(),dp0.end(),0,op);

        return (ans1+ans2)%MOD;
    }
};