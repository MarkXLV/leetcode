class Solution {
public:
    vector<int>build(string &s)
    {
        int n=s.size();
        vector<int>lsp(n,0);
        int i=1;int len=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                lsp[i++]=++len;
            }else
            {
                if(len)
                    len=lsp[len-1];
                else
                    lsp[i++]=0;
            }
        }
        return lsp;
    }
    int strStr(string haystack, string needle) {
        vector<int>lsp=build(needle);
        int i=0;int j=0;
        while(i<haystack.size())
        {
            if(haystack[i]==needle[j])
            {
                i++;j++;
            }
            if(j==needle.size())
            {
                return i-j;
            }
            else if(i<haystack.size() and haystack[i]!=needle[j])
            {
                if(j>0)
                   j=lsp[j-1];
                else
                    i++;
            }
        }
        return -1;

    }
};