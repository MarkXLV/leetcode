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
    bool predictTheWinner(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(auto x:nums)sum+=x;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        long long res=findMax(0,n-1,nums,sum,dp);
        if(res>=(sum+1)/2)
            return true;
        else
            return false;
    };
};