class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (-target <= nums[j] - nums[i] && nums[j] - nums[i] <= target and dp[i]!=-1) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        // for(int i=0;i<n;i++)cout<<dp[i]<<' ';
        return dp[n - 1] != -1 ? dp[n - 1] : -1;
    }
};