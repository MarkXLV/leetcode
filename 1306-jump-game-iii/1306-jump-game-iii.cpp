class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
        function<bool(int)>dfs=[&](int idx)
        {
            if(idx<0 or idx>=n)return false;
            if(vis[idx])return false;
            if(arr[idx]==0)return true;
            vis[idx]=true;
            if(dfs(idx+arr[idx]))return true;
            if(dfs(idx-arr[idx]))return true;
            return false;
        };

        return dfs(start);
    }
};