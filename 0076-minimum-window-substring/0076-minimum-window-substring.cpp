class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq_t;
        for(auto x:t)freq_t[x]++;
        int required=freq_t.size();
        int ans=INT_MAX;
        int start=0;
        int left=0;
        int right=0;
        int n=s.size();
        int formed=0;
        unordered_map<char,int>freq_c;
        while(right<n)
        {
            char ch=s[right];
            freq_c[ch]++;
            if(freq_t.count(ch) && freq_c[ch]==freq_t[ch])
            {
                formed++;
            }

            while(left<=right && formed==required)
            {
                if(right-left+1<ans)
                {
                    ans=right-left+1;
                    start=left;
                }
                char lch=s[left];
                left++;
                freq_c[lch]--;
                if(freq_t.count(lch) && freq_c[lch]<freq_t[lch])
                {
                    formed--;
                }
            }  
            right++;  
        }

        return ans==INT_MAX?"":s.substr(start,ans);
    }
};