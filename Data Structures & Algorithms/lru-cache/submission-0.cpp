class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mpp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);    

    void addNode(Node* newnode){
        Node* temp = tail->prev;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = tail;
        tail->prev = newnode;
    }

    void delNode(Node* delnode){
        Node* prevnode = delnode->prev;
        Node* nextnode = delnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()){
            Node* resnode = mpp[key];
            int res = resnode->val;
            delNode(resnode);
            addNode(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()){
            Node* existingnode = mpp[key];
            existingnode->val = value;
            delNode(existingnode);
            addNode(existingnode);
            return;
        }
        
        if(mpp.size() == cap){
            Node* lru = head->next;
            mpp.erase(lru->key);
            delNode(lru);
            delete lru;
        }
        Node* newnode = new Node(key, value);
        addNode(newnode);
        mpp[key] = newnode;
    }
};
