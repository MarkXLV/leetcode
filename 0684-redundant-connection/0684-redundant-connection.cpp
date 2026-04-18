
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0),rank(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }

        function<int(int)>find=[&](int x)
        {
            if(parent[x]==x)
                return x;
            return parent[x]=find(parent[x]);
        };
        for(auto v:edges)
        {
            int p1=find(v[0]);
            int p2=find(v[1]);
            if(p1!=p2)
            {
                if(rank[p1]>=rank[p2])
                {
                    rank[p1]++;
                    parent[p2]=p1;
                }else
                {
                    rank[p2]++;
                    parent[p1]=p2;
                }
            }else
            {
                return {v[0],v[1]};
            }
        }
        return {};
    }
};