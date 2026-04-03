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
        if(target<0 or idx==candidates.size())return;

        ans.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],ans,idx);
        ans.pop_back();
        solve(candidates,target,ans,idx+1); 
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> ans;
        solve(candidates,target,ans,0);
        return res;
    }
};