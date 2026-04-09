class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v){
            this->key = k;
            this->value = v;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node* node){
        Node* prev = tail->prev;
        node->next = tail;
        node->prev = prev;
        prev->next = node;
        tail->prev = node; 
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->value = value;   
            remove(node);
            insert(node);
        } else {
            if(mp.size() == cap){
                Node* lru = head->next;
                mp.erase(lru->key);
                remove(lru);
                delete lru;        
            }

            Node* nn = new Node(key, value);
            mp[key] = nn;
            insert(nn);            
        }
    }
};