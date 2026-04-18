class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int j=0;
        int i=0;
        int ans=0;
        int mx=0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            int rem=j-i+1-mx;
            if(rem>k)
            {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};