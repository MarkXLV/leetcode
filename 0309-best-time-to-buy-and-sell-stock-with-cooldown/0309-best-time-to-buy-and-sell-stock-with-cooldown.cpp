class Solution {
public:
int n;
int dp[5001][2];
    int solve(int idx,int hold,vector<int>&prices)
    {
        if(idx>=n)return 0;
        int a1=-1,a2=-1;
        if(dp[idx][hold]!=-1)
        return dp[idx][hold];


        if(hold==0)
        {
            a1=-prices[idx]+solve(idx+1,1,prices);
            a2=solve(idx+1,0,prices);
        }else
        {
            a1=prices[idx]+solve(idx+2,0,prices);
            a2=solve(idx+1,1,prices);
        }
        return dp[idx][hold]=max(a1,a2);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,prices);
    }
};