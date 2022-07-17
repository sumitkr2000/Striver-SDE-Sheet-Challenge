class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
        map<int, map<int, multiset<int> > > mp;
        queue<pair< TreeNode*, pair<int, int> > > q;
        
        q.push(make_pair(root, make_pair(0, 0)));
        
        while(!q.empty()) {
            
            pair< TreeNode*, pair<int, int> > temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            mp[hd][level].insert(frontNode -> val);
            
            if(frontNode -> left) {
                q.push(make_pair(frontNode -> left, make_pair(hd-1, level+1)));
            }
            if(frontNode -> right) {
                q.push(make_pair(frontNode -> right, make_pair(hd+1, level+1)));
            }
        }
        
        for(auto i: mp) {
            vector<int> col;
            for(auto j: i.second) {
                    col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
