class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        vector<int>g[100001];
        int n=nums.size();
        if(n==1)return true;
        sort(nums.begin(),nums.end());
        if(nums[0]==1)return false;
        for(auto i:nums)
        {
            for(int x=2;x*x<=i;x++)
            {
                if(i%x==0)
                {
                    g[x].push_back(i);
                    g[i].push_back(x);
                    g[i/x].push_back(i);
                    g[i].push_back(i/x);
                }
            }
        }
        vector<bool>vis(1e5+1,0);
        function<void(int)>dfs=[&](int node)
        {
            vis[node]=true;
            for(auto i:g[node])
                if(!vis[i])dfs(i);
        };
        int cn=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[nums[i]])
               { dfs(nums[i]);cn++;}
            if(cn>1)return false;
        }
        return true;
    }
};