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
            cap++;
        }
        else
        {
            
            if(cap==0)
            {
                Node* nodetodel=last->left;
                remove_node(nodetodel);
                mp.erase(nodetodel->key);
                cap++;
            }
            mp[key]=new Node(key,value);
        }
        // insert
        insert_node(mp[key]);
        cap--;
        
    }
    void insert_node(Node* node)
    {
        first->right->left=node;
        node->right=first->right;
        node->left=first;
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