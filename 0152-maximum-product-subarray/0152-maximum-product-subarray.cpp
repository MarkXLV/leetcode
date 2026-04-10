class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmx=nums[0];
        int currmn=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int tempmx=max(nums[i],max(currmx*nums[i],currmn*nums[i]));
            currmn=min(nums[i],min(currmx*nums[i],currmn*nums[i]));
            currmx=tempmx;
            ans=max(ans,currmx);
        }
        return ans;
    }
};