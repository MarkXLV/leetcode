class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjList;
        vector<int>res;
        int n=numCourses;
        vector<int> indegree(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

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
            res.push_back(front);
            q.pop();
            cnt++;

            for (auto &neigh : adjList[front]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        vector<int>empty;

        return res.size()==n?res:empty;
    }
};