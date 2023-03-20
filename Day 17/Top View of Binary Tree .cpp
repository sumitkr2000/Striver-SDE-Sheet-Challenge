class Solution {
public:
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        map<int, int> mp;
        queue<pair <Node*, int> > q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd) == mp.end()) {
                mp[hd] = frontNode -> data;
            }
            
            if(frontNode -> left) {
                q.push(make_pair(frontNode -> left, hd-1));
            }
            if(frontNode -> right) {
                q.push(make_pair(frontNode -> right,hd+1));
            }
        }
        
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
