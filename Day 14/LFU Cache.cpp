class Node {
public:
    int key;
    int val;
    int cnt;
    Node* prev;
    Node* next;
    
    Node(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
        prev = NULL;
        next = NULL;
    }
};

class List {
public:    
    Node* head;
    Node* tail;
    int size;
        
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    
    void addNode(Node* newNode) {
        
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
        size++;
    }
    
    void deleteNode(Node* temp) {
        
        Node* nextNode = temp -> next;
        Node* prevNode = temp -> prev;
        nextNode -> prev = prevNode;
        prevNode -> next = nextNode;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> address;
    unordered_map<int, List*> freq;
    int size;
    int currSize;
    int minFreq;
    
    LFUCache(int capacity) {
        size = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateList(Node* temp) {
        
        address.erase(temp -> key);
        freq[temp -> cnt] -> deleteNode(temp);
        if(temp -> cnt == minFreq && freq[temp -> cnt] -> size == 0) {
            minFreq++;
        }
        
        List* newList = new List();
        if(freq.find(temp -> cnt + 1) != freq.end()) {
            newList = freq[temp -> cnt + 1];
        }
        
        temp -> cnt += 1;
        newList -> addNode(temp);
        freq[temp -> cnt] = newList;
        address[temp -> key] = temp;
    }
    
    int get(int key) {
        
        if(address.find(key) != address.end()) {
            Node* temp = address[key];
            int data = temp -> val;
            updateList(temp);
            return data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(size == 0) {
            return;
        }
        if(address.find(key) != address.end()) {
            Node* temp = address[key];
            temp -> val = value;
            updateList(temp);
        }
        else {
            if(currSize == size) {
                List* list = freq[minFreq];
                address.erase(list -> tail -> prev -> key);
                list -> deleteNode(list -> tail -> prev);
                currSize--;
            }
            
            currSize++;
            minFreq = 1;
            List* newList = new List();
            
            if(freq.find(minFreq) != freq.end()) {
                newList = freq[minFreq];
            }
            Node* temp = new Node(key, value);
            newList -> addNode(temp);
            address[key] = temp;
            freq[minFreq] = newList;
        }
    }
}
