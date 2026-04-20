class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end())return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            auto [s,l]=q.front();
            q.pop();
            if(s==endWord)return l;
            for(int i=0;i<s.size();i++)
            {
                int ch=s[i];
                for(char c='a';c<='z';c++)
                {
                    s[i]=c;
                    if(words.find(s)!=words.end())
                    {
                        words.erase(s);
                        q.push({s,l+1});
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};