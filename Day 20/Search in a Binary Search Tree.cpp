class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr -> val > val) {
                curr = curr -> left;
            }
            else if(curr -> val < val) {
                curr = curr -> right;
            }
            else {
                return curr;
            }
        }
        return NULL;
    }
};
