class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        unordered_map<int,int>vis;
        int ans=0;
        while(!pq.empty())
        {
            auto [w,u]=pq.top();pq.pop();
            if(vis[u])
                continue;
            vis[u]=1;
            ans+=w;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    int dist=abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
                    pq.push({dist,i});
                }
            }
        }
        return ans;
    }
};