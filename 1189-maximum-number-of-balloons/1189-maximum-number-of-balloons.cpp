class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp = {
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1}
        };
        int ans=INT_MAX;
        unordered_map<char,int>mptext;
        for(auto x:text)
        {
            mptext[x]++;
        }
        for(auto [k,x]:mp)
        {
            ans=min(ans,mptext[k]/mp[k]);
        }
        return ans;
    }
};