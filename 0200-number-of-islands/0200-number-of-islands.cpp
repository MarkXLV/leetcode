#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    int count; // number of components

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = 0;
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    void setCount(int c) {
        count = c;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        // union by rank
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        count--; // one less component
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);

        int landCount = 0;

        // count land cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') landCount++;
            }
        }

        dsu.setCount(landCount);

        // directions: right, down
        int dirs[2][2] = {{0,1},{1,0}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '0') continue;

                for(auto &d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if(ni < m && nj < n && grid[ni][nj] == '1') {
                        int id1 = i * n + j;
                        int id2 = ni * n + nj;
                        dsu.unite(id1, id2);
                    }
                }
            }
        }

        return dsu.count;
    }
};