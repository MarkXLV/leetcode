class DSU
{
public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    
    int find(int x)
    {
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }

    bool unionSet(int a,int b)
    {
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
            return false;
        if(rank[pa]>=rank[pb])
        {
            rank[pa]+=rank[pb];
            parent[pb]=pa;
        }else
        {
            rank[pb]+=rank[pa];
            parent[pa]=pb;
        }

        return true;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        DSU dsu=DSU(n);
        map<int,vector<int>>mp;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            mp[vals[i]].push_back(i);
        }
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans=0;
        for(auto x:mp)
        {
            int val=x.first;
            for(auto y:mp[val])
            {
                for(auto neg:adj[y])
                {
                    if(vals[neg]<=vals[y])
                        dsu.unionSet(neg,y);   // log(n)
                }
            }

            unordered_map<int,int>freq;
            for(auto x:mp[val])
            {
                freq[dsu.find(x)]++;
                ans+=freq[dsu.find(x)];
            }

        }
        return ans;
    }
};