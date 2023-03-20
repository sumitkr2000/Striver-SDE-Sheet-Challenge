class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };
    
    map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size;
    
    LRUCache(int capacity) {
        head -> next = tail;
        tail -> prev = head;
        size = capacity;
    }
    
    void addNode(Node* newNode) {
        
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }
    
    void deleteNode(Node* temp) {
        
        Node* nextNode = temp -> next;
        Node* prevNode = temp -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            int data = temp -> val;
            deleteNode(temp);
            addNode(temp);
            mp[key] = head -> next;
            return data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            deleteNode(temp);
        }
        else if(mp.size() == size) {
            deleteNode(tail -> prev);
        }
        
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};
