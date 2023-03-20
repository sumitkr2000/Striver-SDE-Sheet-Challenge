class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int hl = temp.second.first;
            int vl = temp.second.second;
            
            mp[hl][vl].insert(frontNode -> val);
            
            if(frontNode -> left) {
                q.push({frontNode -> left, {hl-1, vl+1}});
            }
            if(frontNode -> right) {
                q.push({frontNode -> right, {hl+1, vl+1}});
            }
        }
        
        for(auto it: mp) {
            vector<int> temp;
            for(auto j: it.second) {
                for(auto k: j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
