class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        solve(0,nums,res);
        return res;
    }

    void solve(int idx,vector<int>& nums,vector<vector<int>>&res)
    {
        if(idx==nums.size())
        {
            res.push_back(nums);return;
        }

        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,res);
            swap(nums[idx],nums[i]);
        }
    }
};