class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &x:flights)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        pq.push({0,src});
        vector<int>dist(n,INT_MAX-1);
        dist[src]=0;
        while(k>=0 && !pq.empty())
        {
            int size=pq.size();
            while(size--)
            {   
                auto [w,u]=pq.front();pq.pop();

                for(auto [v,t]:adj[u])
                {
                    // dont use global dist[u] in bfs use the current dist //
                    if(dist[v]>w+t)
                    {
                        dist[v]=w+t;
                        cout<<dist[v]<<' '<<v<<' '<<k<<endl;
                        pq.push({dist[v],v});
                    }
                }
            }
            k--;
        }

        return dist[dst]!=INT_MAX-1?dist[dst]:-1;
    }
};
