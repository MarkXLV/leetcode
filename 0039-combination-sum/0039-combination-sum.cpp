class Solution {
public:
vector<vector<int>> res;
    void solve(vector<int>& candidates, int target,vector<int> &ans,int idx)
    {
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        if(target<0)return;

        for(int i=idx;i<candidates.size();i++)
        {
            ans.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,i);
            ans.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> ans;
        solve(candidates,target,ans,0);
        return res;
    }
};