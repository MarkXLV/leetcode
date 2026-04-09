class Solution {
public:
    struct Trie
    {
        unordered_map<char,Trie*>child;
        bool isend=false;
    };
    
    Trie* build(vector<string>& wordDict)
    {
        Trie* root=new Trie();

        for(auto xx:wordDict)
        {
            Trie* curr=root;
            for(auto x:xx)
            {
                if(!curr->child.count(x))
                    curr->child[x]=new Trie();
                
                curr=curr->child[x];
            }
            curr->isend=true;
        }
        return root;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // construct trie for O(n) searching -- previous string generation was taking extra O(k) time.
        Trie* root=build(wordDict);
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            if(!dp[i])continue;
            Trie* curr=root;
            for(int j=i;j<n;j++)
            {
                if(!curr->child.count(s[j]))
                    break;

                curr=curr->child[s[j]];

                if(curr->isend)
                  dp[j+1]=true;
            }
        }
        return dp[n];

    }
};