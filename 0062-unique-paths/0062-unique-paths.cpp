class Solution {
public:
    int uniquePaths(int n, int m) {
          
        vector<vector<int>>grid(n,vector<int>(m,0));
        
          
          for(int i=0;i<m;i++){grid[0][i]=1;}
          for(int i=0;i<n;i++){grid[i][0]=1;}
        
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
       {
        grid[i][j]=(grid[i-1][j]+grid[i][j-1]);}return grid[n-1][m-1];
    }
};