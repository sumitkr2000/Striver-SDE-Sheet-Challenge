class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr -> left) {
                TreeNode* temp = curr -> left;
                while(temp -> right != curr && temp -> right != NULL) {
                    temp = temp -> right;
                }
                if(temp -> right) {
                    ans.push_back(curr -> val);
                    temp -> right = NULL;
                    curr = curr -> right;
                }
                else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
            else {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
        }
        return ans;
    }
};
