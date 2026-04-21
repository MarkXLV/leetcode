class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
        for(auto x:tickets)
        {
            // cout<<x[0]<<' '<<x[1]<<endl;
            adj[x[0]].push(x[1]);
        }
        vector<string>res;
        function<void(string)>dfs=[&](string s)
        {
            while(!adj[s].empty())
            {
                auto t=adj[s].top();
                adj[s].pop();
                dfs(t);
            }
            res.push_back(s);
        };
        
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};