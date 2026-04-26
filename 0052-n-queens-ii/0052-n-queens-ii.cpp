class Solution {
public:
    unordered_map<int,bool>row,col,ldiag,rdiag;
    int ans=0;
    int totalNQueens(int n) {
        permute(n,0);
        return ans;
    }
    void permute(int n,int k)
    {
        if(k==n)
        {
            ans++;
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
                permute(n,k+1);
                row[k]=false;
                col[i]=false;
                rdiag[k-i]=false;
                ldiag[k+i]=false;
            }
        }

    }
};

