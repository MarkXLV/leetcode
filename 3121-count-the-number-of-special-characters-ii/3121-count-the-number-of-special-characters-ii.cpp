class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>first;
        unordered_map<char,int>last;
        for(int i=0;i<word.size();i++)
        {
            char x=word[i];
            if(first.count(x)==0)
            {
                first[x]=i;
            }
            last[x]=i;
        }
        int cn=0;
        for(char c='a';c<='z';c++)
        {
            if(last.count(c) && first.count('A'+(c-'a')) && last[c]<first['A'+(c-'a')])
            {
                cn++;
            }
        }
        return cn;
    }
};