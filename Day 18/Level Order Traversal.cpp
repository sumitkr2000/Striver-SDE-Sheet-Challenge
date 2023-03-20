class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            
            for(int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp -> val);
                
                if(temp -> left) {
                    q.push(temp -> left);
                }
                if(temp -> right) {
                    q.push(temp -> right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
