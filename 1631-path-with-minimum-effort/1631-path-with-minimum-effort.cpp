class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> heights;
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->heights = heights;
        this->ROWS = heights.size();
        this->COLS = heights[0].size();
        this->visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        int l = 0, r = 1'000'000, res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            for (auto& row : visited) {
                fill(row.begin(), row.end(), false);
            }
            if (dfs(0, 0, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }

private:
    bool dfs(int r, int c, int limit) {
        if (r == ROWS - 1 && c == COLS - 1) {
            return true;
        }

        visited[r][c] = true;
        for (const auto& dir : directions) {
            int newR = r + dir[0];
            int newC = c + dir[1];
            if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS || visited[newR][newC]) {
                continue;
            }
            if (abs(heights[newR][newC] - heights[r][c]) > limit) {
                continue;
            }
            if (dfs(newR, newC, limit)) {
                return true;
            }
        }
        return false;
    }
};