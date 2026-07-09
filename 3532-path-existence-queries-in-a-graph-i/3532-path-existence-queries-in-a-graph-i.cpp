class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int i=0;int j=0;
        vector<int>g[n];
        while(j<n and i<n)
        {
            if(i==j)
            {
                j++;
            }else if(abs(nums[i]-nums[j])<=maxDiff)
            {
                g[i].push_back(j);
                g[j].push_back(i);
                j++;
            }else
            {
                i++;
            }
        }
        vector<int>col(n,-1);
        int cn=1;
        function<void(int,int)>dfs=[&](int node,int cn)
        {
            col[node]=cn;
            for(auto x:g[node])
            {
                if(col[x]==-1)
                    dfs(x,cn);
            }
        };
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                dfs(i,cn);
                cn++;
            }
        }

        vector<bool>res;
        for(auto x:queries)
        {
            int i=x[0];
            int j=x[1];
            if(col[i]==col[j])
            {
                res.push_back(true);
            }else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};