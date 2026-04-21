class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        vector<string> res;
        
        // Build graph
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        // DFS function
        function<void(string)> dfs = [&](string airport) {
            while (!adj[airport].empty()) {
                string next = adj[airport].top();
                adj[airport].pop();
                dfs(next);
            }
            res.push_back(airport);
        };

        // Start DFS from 'JFK'
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};