class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr -> left) {
                TreeNode* temp = curr -> left;
                while(temp -> right != NULL) {
                    temp = temp -> right;
                }
                temp -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};
