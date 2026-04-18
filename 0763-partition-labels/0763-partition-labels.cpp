class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            mp[s[i]]=max(mp[s[i]],i);
        }
        int l=0;int r=0;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            r=max(r,mp[s[i]]);
            if(i==r)
            {
                res.push_back(r-l+1);
                l=i+1;
            }
        }
        return res;
            
    }
};