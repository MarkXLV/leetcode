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
            insert_node(key,ans);

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            // delete 
            remove_node(mp[key]);
        }
        else
        {
            if(cap==0)
            {
                remove_node(last->left);
            }
        }
        // insert
        insert_node(key,value);
        
    }



    void insert_node(int key,int val)
    {
        mp[key]=new Node(key,val);
        first->right->left=mp[key];
        mp[key]->right=first->right;
        mp[key]->left=first;
        first->right=mp[key];
        cap--;
    }

    void remove_node(Node* node)
    {
        node->left->right=node->right;
        node->right->left=node->left;
        mp.erase(node->key);
        delete(node);
        cap++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */