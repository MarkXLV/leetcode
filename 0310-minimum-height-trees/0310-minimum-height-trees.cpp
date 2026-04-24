class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>adj;
    void dfs(int node,int par)
    { 
        for(auto x:adj[node])
        {
            if(x!=par)
            {
                dfs(x,node);
                int k=dp[x][0]+1;
                if(k>dp[node][0])
                {
                    dp[node][1]=dp[node][0];
                    dp[node][0]=k;
                }else if(k>dp[node][1])
                {
                    dp[node][1]=k;
                }
            }
        }
    }

    void dfs1(int node,int par,int mx)
    {
        if(mx>dp[node][0])
        {
            dp[node][1]=dp[node][0];
            dp[node][0]=mx;
        }else if(mx>dp[node][1])
        {
            dp[node][1]=mx;
        }

        for(auto x:adj[node])
        {
            if(x!=par)
            {
                // node in maxumum path
                if(dp[x][0]+1==dp[node][0])
                {
                    dfs1(x,node,dp[node][1]+1);
                }else
                {
                    dfs1(x,node,dp[node][0]+1);
                }
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        dp.assign(n,vector<int>(2,0));
        adj.assign(n,vector<int>());
        for(auto &x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1);
        dfs1(0,-1,0);
        int mn=INT_MAX;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,dp[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i][0]==mn)
                res.push_back(i);
        }
        return res;

    }
};