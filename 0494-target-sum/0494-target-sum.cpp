class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int>curr;
        curr[0]=1;
        int n=nums.size();

        for(int i=n-1;i>=0;i--)
        {
            unordered_map<int,int>temp;
            for(auto [k,v]:curr)
            {
                temp[k-nums[i]]+=v;
                temp[k+nums[i]]+=v;
            }
            curr=temp;
        }
        
        return curr[target];
    }
};