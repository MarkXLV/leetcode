class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case for empty string
        
        for (int i = 1; i < n; ++i) {
            int oneDigit = stoi(s.substr(i, 1));
            int twoDigits = stoi(s.substr(i - 1, 2));
            
            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                // consider two integers "12"
                    dp[i] += i>=2?dp[i - 2]:1;   
            }
        }
        return dp[n-1];
    }
};