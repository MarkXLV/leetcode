class Solution {
public:
    vector<vector<string>>res;
    unordered_map<int,bool>row,col,ldiag,rdiag;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        permute(n,0,board);
        return res;
    }
    void permute(int n,int k,vector<string>&board)
    {
        if(k==n)
        {
            res.push_back(board);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(!row[k] && !col[i] && !rdiag[k-i] && !ldiag[k+i])
            {
                cout<<i<<k<<endl;
                row[k]=true;
                col[i]=true;
                rdiag[k-i]=true;
                ldiag[k+i]=true;
                board[k][i]='Q';
                permute(n,k+1,board);
                row[k]=false;
                col[i]=false;
                rdiag[k-i]=false;
                ldiag[k+i]=false;
                board[k][i]='.';
            }
        }

    }
};

