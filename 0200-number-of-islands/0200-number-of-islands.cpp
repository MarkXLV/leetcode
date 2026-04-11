class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        DSU dsu(rows * cols);
        int numIslands = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    int index = i * cols + j;

                    // Union with right and down neighbors
                    if (j + 1 < cols && grid[i][j + 1] == '1') {
                        dsu.unite(index, i * cols + (j + 1));
                    }
                    if (i + 1 < rows && grid[i + 1][j] == '1') {
                        dsu.unite(index, (i + 1) * cols + j);
                    }
                }
            }
        }

        unordered_set<int> uniqueIslands;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    int root = dsu.find(i * cols + j);
                    uniqueIslands.insert(root);
                }
            }
        }

        return uniqueIslands.size();
    }
};