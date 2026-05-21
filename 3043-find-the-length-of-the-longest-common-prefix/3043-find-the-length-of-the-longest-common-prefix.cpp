struct Node{
    unordered_map<char,Node*>mp;
};
class Trie
{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        };
        void insert(vector<int>&a)
        {
            for(auto x:a)
            {
                string s=to_string(x);
                Node* temp=root;
                for(auto xx:s)
                {
                    if(!temp->mp[xx])
                    {
                        temp->mp[xx]=new Node();
                    }
                    temp=temp->mp[xx];
                }
            }
        }
        int find(int x)
        {
            string s=to_string(x);
            Node* temp=root;
            int cn=0;
            for(auto xx:s)
            {
                if(!temp->mp[xx])
                    return cn;
                temp=temp->mp[xx];
                cn++;
            }
            return cn;
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        trie.insert(arr1);
        int ans=0;
        for(auto x:arr2)
        {
            int k=trie.find(x);
            ans=max(ans,k);
        }
        return ans;
    }
};