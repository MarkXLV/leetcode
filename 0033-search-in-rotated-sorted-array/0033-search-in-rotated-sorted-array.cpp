class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                return mid;

            }else if(nums[mid]<target)
            {
                if(nums[0]>nums[mid] and target>nums[n-1])
                {
                    r=mid-1;
                }else
                {
                    l=mid+1;
                }
            }else
            {
                if(nums[mid]>nums[n-1] and target<nums[0])
                {
                    l=mid+1;
                }else
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};