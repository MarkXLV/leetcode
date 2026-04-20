class Solution {
public:
    class Trie
    {
        public:
            unordered_map<char,Trie*>mp;
            string word="";
    };

    Trie* buildTrie(vector<string>& words)
    {
        Trie* root=new Trie();
        for(auto x:words)
        {
            Trie* curr=root;
            for(auto ch:x)
            {
                if(!curr->mp.count(ch))
                {
                    curr->mp[ch]=new Trie();
                }
                curr=curr->mp[ch];
            }
            curr->word=x;
        }
        return root;
    }
    void dfs(int x,int y,vector<string>&res,Trie* p,vector<vector<char>>& board)
    {     
        
        char ch=board[x][y];

        if(!p->mp[ch])return;

        p=p->mp[ch];
        if(p->word!="")
        {
            res.push_back(p->word);
            p->word="";
        }

        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        board[x][y]='#';
        for(auto &[dx,dy]:dir)
        {
            int nx=x+dx;
            int ny=y+dy;
            if(nx<0 or nx>=board.size() or ny<0 or ny>=board[0].size() or board[nx][ny]=='#')continue;
            dfs(nx,ny,res,p,board);
        }
        board[x][y]=ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* p=buildTrie(words);
        int n=board.size();
        int m=board[0].size();
        vector<string>res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                    dfs(i,j,res,p,board);
            }
        }
        return res;
    }
};