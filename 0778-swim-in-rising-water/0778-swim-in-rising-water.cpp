class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        auto canSwim=[&](int t)
        {
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            queue<pair<int,int>>q;
            q.push({0,0});
            vis[0][0]=true;
            vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
            while(!q.empty())
            {
                auto [x,y]=q.front();
                q.pop();
                if(x==n-1 and y==m-1)return true;
                for(auto &[dx,dy]:dir)
                {
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny] or grid[nx][ny]>t)continue;
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
            return false;   
        };

        int l=grid[0][0];
        int r=n*n-1;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(canSwim(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};


