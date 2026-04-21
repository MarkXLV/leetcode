class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // n=4
        // l=1            l=2          l=3
        // left=1,4.       left,1,3     1,2
        // right=1,4       right=2,4.   right=3,4

        // 1,1,    2,2.  3,3,   4,4
        // 1,2.    2,3.  3,4. 
        // 1,3.    2,4
        // 1,4
        // handle edge cases
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int lenght=1;lenght<=n;lenght++)
        {
            for(int left=1;left<=n-lenght+1;left++)
            {
                int right=left+lenght-1;
                // nums[k] is the last ballon to be burst in the subarray of size L ,ranging from [left,right]
                for(int k=left;k<=right;k++)
                {
                    int coins=nums[left-1]*nums[k]*nums[right+1]+dp[left][k-1]+dp[k+1][right];
                    dp[left][right]=max(coins,dp[left][right]);
                }
            }
        }
        return dp[1][n];
    }
};