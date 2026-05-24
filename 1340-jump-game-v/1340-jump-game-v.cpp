class Solution {
public:
    int solve(int idx,vector<int>& arr,int d,int n,vector<int>&dp)
    {
        if(idx<0 or idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans=1;
        int k=idx+1;
        while(k<n && k<=idx+d && arr[idx]>arr[k])
        {
            ans=max(ans,1+solve(k,arr,d,n,dp));
            k++;
        }
        k=idx-1;
        while(k>=0 && k>=idx-d && arr[idx]>arr[k])
        {
            ans=max(ans,1+solve(k,arr,d,n,dp));
            k--;
        }
        return dp[idx]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
        int n=arr.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,solve(i,arr,d,n,dp));
        }
        return ans;
    }
};