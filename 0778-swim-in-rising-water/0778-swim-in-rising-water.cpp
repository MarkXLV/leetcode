class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        int dp[50][50][2501];
        memset(dp,-1,sizeof(dp));
        function<int(int,int,int)>dfs=[&](int x,int y,int mx)
        {
            if(x==n-1 and y==m-1)
            {
                return max(grid[x][y],mx);
            }
            if(dp[x][y][mx]!=-1)return dp[x][y][mx];

            int res=INT_MAX;
            vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
            int val=grid[x][y];
            grid[x][y]=INT_MAX;
            for(auto &[dx,dy]:dir)
            {
                int nx=x+dx;
                int ny=y+dy;
                if(nx<0 or ny<0 or nx>=n or ny>=m or grid[nx][ny]==INT_MAX)continue;
                int cmax=dfs(nx,ny,max(mx,val));
                res=min(res,cmax);
            }
            grid[x][y]=val;
            return dp[x][y][mx]=res;
        };
        return dfs(0,0,0);
    }
};