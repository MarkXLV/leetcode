struct TrieNode
{
    unordered_map<char,TrieNode*>child;
    bool isend=false;
    TrieNode(){}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto ch:word)
        {
            if(!node->child.count(ch))
            {
                node->child[ch]=new TrieNode();
            }
            node=node->child[ch];
        }
        node->isend=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(auto ch:word)
        {
            if(!node->child.count(ch))
            {
                return false;
            }
            node=node->child[ch];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(auto ch:prefix)
        {
            if(!node->child.count(ch))
            {
                return false;
            }
            node=node->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */