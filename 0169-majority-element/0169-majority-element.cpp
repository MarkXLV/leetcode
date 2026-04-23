class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can=nums[0];
        int f=1;
        for(int i=1;i<nums.size();i++)
        {
            if(f==0)
            {
               can=nums[i];
               f++;
            }else if(nums[i]==can)
            {
                f++;
            }else
            {
                f--;
            }
        }
        return can;
    }
};