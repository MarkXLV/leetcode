class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>tres;
        permute(1,k,tres,res,n);
        return res;
    }
    void permute(int i,int k,vector<int>& tres,vector<vector<int>>&res,int n)
    {
        if(tres.size()==k)
        {
            res.push_back(tres);
            return;
        }
        for(int x=i;x<=n;x++)
        {
            tres.push_back(x);
            permute(x+1,k,tres,res,n);
            tres.pop_back();
        }
    }
};