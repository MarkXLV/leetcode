class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res;
        map<int,int>mp;
        for(auto x:arr)mp[x];
        int cn=1;
        for(auto [x,v]:mp){
            mp[x]=cn;
            cn++;
        };
        for(auto x:arr)
        {
            res.push_back(mp[x]);
        }
        return res;
    }
};