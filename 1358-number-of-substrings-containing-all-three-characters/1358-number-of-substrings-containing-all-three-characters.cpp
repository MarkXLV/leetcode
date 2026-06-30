class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;
        int ans=0;
        int n=s.size();
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp['a']>=1 and mp['b']>=1 and mp['c']>=1)
            {
                ans+=(n-i);
                while(j<=i)
                {
                    mp[s[j]]--;
                    j++;
                    if(mp['a']==0 or mp['b']==0 or mp['c']==0)
                    {
                        break;
                    }else
                    {
                        ans+=(n-i);
                    }
                }
            }
        }
        return ans;
    }
};