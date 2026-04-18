class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0) {
                return 0;
            }
            grid[x][y] = 0;  // mark as visited
            int area = 1;
            for (const auto& dir : directions) {
                area += dfs(x + dir[0], y + dir[1]);
            }
            return area;
        };
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }
        return maxArea;
    }
};