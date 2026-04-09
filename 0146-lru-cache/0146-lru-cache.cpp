class LRUCache {
public:
    struct Node
    {
        int key;
        int val;
        Node* right=NULL;
        Node* left=NULL;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };

    // first--> last
    int cap;
    unordered_map<int,Node*>mp;
    Node* first;
    Node* last;

    LRUCache(int capacity) {
        cap=capacity;
        first=new Node(-1,-1);
        last=new Node(-1,-1);
        first->right=last;
        last->left=first;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            cout<<key<<endl;
            int ans=mp[key]->val;
            // delete 
            Node* node=mp[key];
            node->left->right=node->right;
            node->right->left=node->left;
            mp.erase(key);
            delete(node);
            // insert
            mp[key]=new Node(key,ans);
            first->right->left=mp[key];
            mp[key]->right=first->right;
            mp[key]->left=first;
            first->right=mp[key];

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            // delete 
            Node* node=mp[key];
            node->left->right=node->right;
            node->right->left=node->left;
            mp.erase(key);
            delete(node);
            cap++;
        }
        else
        {
            if(cap==0)
            {
                Node* node=last->left;
                node->left->right=node->right;
                node->right->left=node->left;
                mp.erase(node->key);
                delete(node);
                cap++;
                
            }
        }
        // insert
        mp[key]=new Node(key,value);
        first->right->left=mp[key];
        mp[key]->right=first->right;
        mp[key]->left=first;
        first->right=mp[key];
        cap--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */