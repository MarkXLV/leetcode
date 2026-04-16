class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int s=i+1;
            int e=n-1;
            while(s<e)
            {
                int sum=nums[s]+nums[e]+nums[i];
                if(sum==0)
                {
                    res.push_back({nums[s],nums[e],nums[i]});
                    s++;e--;
                    while(s<n and nums[s]==nums[s-1])s++;
                    while(e>0 and nums[e]==nums[e+1])e--;
                }else if(sum>0)
                {
                    e--;
                }else
                {
                    s++;
                }
            } 
        }
        return res;
    }
};