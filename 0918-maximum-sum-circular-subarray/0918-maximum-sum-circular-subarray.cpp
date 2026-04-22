class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=INT_MIN;
        int ans1=INT_MAX;
        int currp=0;
        int currn=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            currp+=nums[i];
            currn+=nums[i];
            ans=max(ans,currp);
            ans1=min(ans1,currn);
            if(currp<0)currp=0;
            if(currn>0)currn=0;
        }
        int k=sum!=ans1?sum-ans1:INT_MIN;
        return max(ans,k);
    }
    
};
