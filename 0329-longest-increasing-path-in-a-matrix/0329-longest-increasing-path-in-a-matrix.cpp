class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unsigned long long res=1;
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));

        function<unsigned long long(int,int)>dfs=[&](int x,int y)
        {
            unsigned long long &ans=dp[x][y];
            if(ans!=0)
                return ans;

            vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
            ans=1;
            for(auto &[dx,dy]:dir)
            {
                int nx=x+dx;
                int ny=y+dy;
                if(nx<0 or nx>=n or ny<0 or ny>=m or matrix[nx][ny]<=matrix[x][y])continue;
                ans=max(ans,1+dfs(nx,ny));
            }
            return ans;
        };

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=max(res,dfs(i,j));
            }
        }
        return res;
    }
};




// class Solution {
// public:
//     int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         std::vector<std::vector<int>> memo(n, std::vector<int>(m, 0));
//         int ans = 0;
        
//         std::function<int(int, int, int)> dfs = [&](int x, int y, int prevValue) {
//             if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= prevValue) return 0;
//             if (memo[x][y] != 0) return memo[x][y];
            
//             int maxLength = 1;
//             std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//             for (auto [dx, dy] : directions) {
//                 int newLength = 1 + dfs(x + dx, y + dy, matrix[x][y]);
//                 maxLength = std::max(maxLength, newLength);
//             }
//             memo[x][y] = maxLength;
//             return maxLength;
//         };
        
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 ans = std::max(ans, dfs(i, j, -1));
//             }
//         }
//         return ans;
//     }
// };