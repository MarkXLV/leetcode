class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        // union by size
        if (size[pa] < size[pb]) swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];
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