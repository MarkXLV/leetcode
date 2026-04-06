class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        function<bool(int,int,int)> solve=[&](int idx,int i,int j)
        {
            if(idx>=word.size())
                return true;
            
            if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[idx])return false;
            board[i][j]='#';
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            for(int k=0;k<4;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(solve(idx+1,ni,nj))
                    return true;
            }
            board[i][j]=word[idx];
            return false;
        };
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(0,i,j))
                return true;
            }
        }
        return false;
         
    }
};