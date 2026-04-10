class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1 or nums[n-1]>nums[0])return nums[0];
        int l=0;int h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(mid-1>=0 and nums[mid-1]>nums[mid])return nums[mid];
            if(nums[mid]>=nums[0])
                l=mid+1;
            else
                h=mid-1;
        }
        return nums[l];
    }
};