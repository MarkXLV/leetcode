class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            curr*=nums[i];
            ans=max(ans,curr);
            if(curr==0)
            {
                curr=1;
            }
        }
        reverse(nums.begin(),nums.end());
        curr=1;
        for(int i=0;i<nums.size();i++)
        {
            curr*=nums[i];
            ans=max(ans,curr);
            if(curr==0)
            {
                curr=1;
            }
        }

        return ans;
    }
};