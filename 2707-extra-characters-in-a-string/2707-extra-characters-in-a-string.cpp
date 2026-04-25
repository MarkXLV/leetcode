// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
//         set<string>st;
//         for(auto i:dictionary)st.insert(i);
//         int n=s.size();
//         vector<int>dp(n+1,n);
//         dp[0]=0;
//         for(int i=1;i<=n;i++)
//         {
//             dp[i]=dp[i-1]+1;
//             for(int x=i;x>=1;x--)
//             {
//                 if(st.count(s.substr(x-1,i-x+1)))
//                 {
//                     dp[i]=min(dp[i],dp[x-1]);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

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

    int minExtraChar(string s, vector<string>& wordDict) {
        // construct trie for O(n) searching -- previous string generation was taking extra O(k) time.
        Trie* root=build(wordDict);
        int n=s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=min(dp[i],dp[i-1]+1);
            Trie* curr=root;
            for(int j=i;j<=n;j++)
            {
                if(!curr->child.count(s[j-1]))
                    break;

                curr=curr->child[s[j-1]];

                if(curr->isend)
                  dp[j]=min(dp[j],dp[i-1]);
            }
        }
        return dp[n];

    }
};