class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;int j=1;
        int n=nums.size();
        int prev=nums[0];
        while(j<n)
        {
            if(nums[j]!=prev)
            {
                prev=nums[j];
                swap(nums[j],nums[i+1]);
                i++;
                j++;
            }else
            {
                prev=nums[j];
                j++;
            }
        }
        return i+1;
    }
};