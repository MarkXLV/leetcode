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
            if(i>idx && candidates[i]==candidates[i-1])
            continue;
            ans.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,i+1);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,0);
        return res;
    }
};