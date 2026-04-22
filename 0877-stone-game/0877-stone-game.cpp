class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int k=solve(0,piles.size()-1,piles,dp);
        if(k>0)return true;
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