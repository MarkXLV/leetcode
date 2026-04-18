class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &x:times)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX-1);
        dist[k]=0;
        while(!pq.empty())
        {
            auto [w,u]=pq.top();pq.pop();
            // remove stale nodes
            if(w>dist[u])
                continue;
            for(auto [v,t]:adj[u])
            {
                if(dist[v]>dist[u]+t)
                {
                    dist[v]=dist[u]+t;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dist[i]);

        return ans!=INT_MAX-1?ans:-1;
    }
};