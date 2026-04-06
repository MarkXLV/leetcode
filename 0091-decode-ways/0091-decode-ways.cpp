class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,INT_MAX);
        function<int(int)>dfs=[&](int idx)
        {
            if(idx>=n)
                return 1;
            if(s[idx]-'0'==0)return 0;
            if(dp[idx]!=INT_MAX)
                return dp[idx];
            int ans=0;
            if(s[idx]=='1')
            {
                ans+=dfs(idx+1);
                if(idx+1<n)
                    ans+=dfs(idx+2);
            }else if(s[idx]=='2')
            {
                ans+=dfs(idx+1);
                if(idx+1<n and s[idx+1]-'0'<=6)
                    ans+=dfs(idx+2);
            }
            else
            {
                ans+=dfs(idx+1);
            }
            return dp[idx]=ans;
        };
        return dfs(0);
    }
};