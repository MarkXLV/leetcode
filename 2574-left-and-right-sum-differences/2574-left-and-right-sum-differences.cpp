class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int sum=0;
        for(auto x:nums)sum+=x;
        int pre=0;
        for(int i=0;i<n;i++)
        {
            int a1=pre;
            int a2=sum-pre-nums[i];
            ans[i]=abs(a1-a2);
            pre+=nums[i];
        }
        return ans;
    }
};