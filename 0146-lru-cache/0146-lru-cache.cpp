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
            remove_node(mp[key]);
            // insert
            insert_node(mp[key]);

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            // delete 
            mp[key]->val=value;
            remove_node(mp[key]);
            insert_node(mp[key]);
        }
        else
        {
            if(mp.size()==cap)
            {
                Node* nodetodel=last->left;
                mp.erase(nodetodel->key);
                remove_node(nodetodel);
            }
            mp[key]=new Node(key,value);
            insert_node(mp[key]);
        }        
    }
    void insert_node(Node* node)
    {
        node->right=first->right;
        node->left=first;
        first->right->left=node; 
        first->right=node;
    }

    void remove_node(Node* node)
    {
        node->left->right=node->right;
        node->right->left=node->left;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */