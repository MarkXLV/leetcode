class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int l=roads.size();
        vector<vector<pair<int,int>>>g(n+1);
        for(int i=0;i<l;i++)
        {
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        long long ans=INT_MAX;
        vector<int>vis(n+1,0);
        function<void(int,int)>dfs=[&](int node,int par)
        {
            vis[node]=true;
            for(auto i:g[node])
            {
                ans=min(ans,1LL*i.second);
                if(!vis[i.first])
                {
                    dfs(i.first,node);
                }
            }
        };
        dfs(1,-1);
        return ans;
    }
};