class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs("",0,0,res,n);
        return res;
    }

    void dfs(string curr,int open,int close,vector<string>&res,int n)
    {
        if(open==close and open==n)
        {
            res.push_back(curr);
            return;
        }

        if(open<n)
        {
            dfs(curr+"(",open+1,close,res,n);
        }

        // because open cannot be applied before close and always it should be less than or equal to open for valid parenthesis
        if(close<open)
        {
            dfs(curr+")",open,close+1,res,n);
        }

    }
};