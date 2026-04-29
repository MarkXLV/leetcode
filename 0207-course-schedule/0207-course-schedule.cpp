class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& e) {
        unordered_map<int,list<int>> adjList;
        vector<int> indegree(n, 0);

        for (int i = 0; i < e.size(); i++) {
            int u = e[i][0];
            int v = e[i][1];

            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            cnt++;

            for (auto &neigh : adjList[front]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return cnt == n;
    }
};