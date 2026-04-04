class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cn=0;
        vector<int>res;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int n=matrix.size();
        int m=matrix[0].size();
        int dir=0;
        int x=0,y=-1;
        while(cn<n*m)
        {
            x+=dx[dir];
            y+=dy[dir];

            // changing dirextions;
            if(x>=n or y>=m or x<0 or y<0 or matrix[x][y]==INT_MAX)
            {
                x-=dx[dir];
                y-=dy[dir];
                dir=(dir+1)%4;
            }else
            {
                res.push_back(matrix[x][y]);
                matrix[x][y]=INT_MAX;
                cn++;
            }
        }
        return res;
    }
};