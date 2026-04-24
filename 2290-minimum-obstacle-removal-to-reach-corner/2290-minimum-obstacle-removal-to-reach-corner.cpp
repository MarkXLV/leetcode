class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
       deque<tuple<int,int,int>>dq;
       dq.push_front({0,0,0}); dist[0][0]=0;
       vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
       while(!dq.empty())
       {
           auto [d,x,y]=dq.front();dq.pop_front();
           if(x==(n-1) && y==(m-1))return d;
           for(auto &[dx,dy]:dir)
           {
                int nx=x+dx;
                int ny=y+dy;
                if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
                int currd=d+grid[nx][ny];
                if (currd < dist[nx][ny]) {
                    dist[nx][ny] = currd;
                    if(grid[nx][ny]==0)
                        dq.push_front({currd,nx,ny});
                    else
                        dq.push_back({currd,nx,ny});
                }
               
           }

       }
       return -1;
    }
};