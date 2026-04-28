class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> count(n, 1);
        vector<int> answer(n, 0);
        dfs(0, -1, graph, count, answer);
        dfs2(0, -1, graph, count, answer, n);
        return answer;
    }

private:
    void dfs(int node, int parent, const vector<vector<int>>& graph, vector<int>& count, vector<int>& answer) {
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, graph, count, answer);
            count[node] += count[neighbor];
            answer[node] += answer[neighbor] + count[neighbor];
        }
    }

    void dfs2(int node, int parent, const vector<vector<int>>& graph, vector<int>& count, vector<int>& answer, int n) {
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            answer[neighbor] = answer[node] - count[neighbor] + (n - count[neighbor]);
            dfs2(neighbor, node, graph, count, answer, n);
        }
    }
};