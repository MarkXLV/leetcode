class Solution {
public:
    long long findMax(int start,int end,vector<int>&nums,long long sum,vector<vector<int>>&dp)
    {
        if(start>end || start>=nums.size() || end<0)return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];

        long long ans=0;

        if(start==end)return dp[start][end]=nums[start];

        // think of minimizing the opponent choice
        long long choice1=findMax(start+1,end,nums,sum-nums[start],dp);
        long long choice2=findMax(start,end-1,nums,sum-nums[end],dp);

        return dp[start][end]=sum-min(choice1,choice2);
    }
    bool predictTheWinner(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int k=solve(0,piles.size()-1,piles,dp);
        if(k>=0)return true;
        return false;
    }
    int solve(int l,int r,vector<int>& piles,vector<vector<int>>&dp)
    {
        if(l==r)return piles[l];
        if(l>r)return 0;
        int &ans=dp[l][r];
        if(ans!=-1)return ans;
        int first=piles[l]-solve(l+1,r,piles,dp);
        int last=piles[r]-solve(l,r-1,piles,dp);
        return ans=max(first,last);
    }
};