class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,false);
        dp[0]=true;
        unordered_map<string,bool>mp;
        for(auto x:wordDict)
        mp[x]=true;

        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j>=0;j--)
            {
                temp=s[j]+temp;
                if(mp[temp])
                {
                    dp[i+1]|=dp[j];
                }
            }
        }
        return dp[n];
    }
};