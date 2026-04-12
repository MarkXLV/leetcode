class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int take=0;int notake=0;
        for(int i=0;i<n-1;i++)
        {
            int ctake=nums[i]+notake;
            int cnotake=max(take,notake); 
            take=ctake;
            notake=cnotake;
        }
        int ans=max(take,notake);
        take=0;notake=0;
        for(int i=1;i<n;i++)
        {
            int ctake=nums[i]+notake;
            int cnotake=max(take,notake); 
            take=ctake;
            notake=cnotake;
        }
        ans=max(ans,max(take,notake));
        return ans;


    }
};