class Trie
{
    public:
        bool end;
        Trie* adj[26];
        Trie()
        {
            this->end=false;
            for(int i=0;i<26;i++)
            {
                this->adj[i]=NULL;
            }
        }
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* p=root;
        for(auto x:word)
        {
            if(p->adj[x-'a']==NULL)
                p->adj[x-'a']=new Trie();
            p=p->adj[x-'a'];
        }
        p->end=true;
    }
    
    bool search(string word) {
        Trie* p=root;
        return help(p,word,0);
    }

    bool help(Trie* root,string &word,int idx)
    {
        if(idx==word.size())return root->end;
        
        if(word[idx]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(root->adj[i])
                {
                    if(help(root->adj[i],word,idx+1))
                    return true;
                }
            }
            return false;

        }else
        {
            if(root->adj[word[idx]-'a'])
            {
                return help(root->adj[word[idx]-'a'],word,idx+1);

            }else
            {
                return false;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */