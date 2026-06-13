class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto x:words)
        {
            int res=0;
            for(auto y:x)
            {
                res+=weights[y-'a'];
                res%=26;
            }
            ans+=((25-res)+'a');
        }
        return ans;
    }
};