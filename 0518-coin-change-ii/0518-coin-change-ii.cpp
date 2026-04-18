class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int>dp(amount+1,0);
        dp[0]=1;
        for(auto x:coins)
        {
            for(int j=x;j<=amount;j++)
            {
                dp[j]+=dp[j-x];
            }
        }
        return dp[amount];
    }
};