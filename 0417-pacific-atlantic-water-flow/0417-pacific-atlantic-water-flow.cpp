class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> result;

        // Helper function to perform DFS
        function<void(int,int,vector<vector<int>>&)>dfs = [&](int r, int c, vector<vector<int>>& ocean) {
            static vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            ocean[r][c] = 1;
            for (auto& d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, ocean);
                }
            }
        };

        // Perform DFS from all Pacific border cells
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pacific);
            dfs(i, n - 1, atlantic);
        }
        for (int i = 0; i < n; ++i) {
            dfs(0, i, pacific);
            dfs(m - 1, i, atlantic);
        }

        // Collect cells that can reach both oceans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};