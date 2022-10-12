class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) {
            return NULL;
        }
        
        unordered_map<Node*, Node*> mp;
        
        Node* copyHead = new Node(node -> val);
        mp[node] = copyHead;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            for(auto it: front -> neighbors) {
                if(mp.find(it) == mp.end()) {
                    Node* copyNode = new Node(it -> val);
                    mp[front] -> neighbors.push_back(copyNode);
                    mp[it] = copyNode;
                    q.push(it);
                }
                else {
                    mp[front] -> neighbors.push_back(mp[it]);
                }
            }
        }
        return copyHead;
    }
};
