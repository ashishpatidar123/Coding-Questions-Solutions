class LRUCache {
public:
    class Node{
    public:
        Node* prev;
        Node* next;
        int key;
        int val;
        Node(int keys, int value){
            key = keys;
            val = value;
        }
    };
    int size;
    unordered_map<int,Node*>m;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode){
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delNode->next = NULL;
        delNode->prev = NULL;
    }
    void moveTofront(Node* node){
        deleteNode(node);
        addNode(node);
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            int ans = node->val;
            moveTofront(node);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            node->val = val;
            moveTofront(node);
        }
        else{
            if(m.size()==size){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addNode(new Node(key,val));
            m[key] = head->next;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
