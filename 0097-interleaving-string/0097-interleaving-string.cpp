class Solution {
public:
int n,m,p;
bool canmake(string &s1,string &s2,string &s3,int i,int j,int k)
{
    if(i==n and j==m and k==p)return true;
    if(i<n and s1[i]==s3[k] and canmake(s1,s2,s3,i+1,j,k+1))return true;
    if(j<m and s2[j]==s3[k] and canmake(s1,s2,s3,i,j+1,k+1))return true;return false;
    
}
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.length();m=s2.length();p=s3.length();
        if(n+m!=p)return false;
        // return canmake(s1,s2,s3,0,0,0);
        int dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        dp[i][0]=dp[i-1][0] && s1[i-1]==s3[i-1];
        for(int i=1;i<=m;i++)
        dp[0][i]=dp[0][i-1] && s2[i-1]==s3[i-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1] || dp[i][j-1] &&  s2[j-1]==s3[i+j-1];
            }
        }
        return dp[n][m];
    }
};