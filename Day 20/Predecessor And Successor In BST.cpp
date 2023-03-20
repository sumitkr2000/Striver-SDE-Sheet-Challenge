class Solution {
public:
    vector<int> predecessorSuccessor(TreeNode* root, int key) {

        int pre = -1, suc = -1;
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr -> key < key) {
                pre = curr;
                curr = curr -> right;
            }
            else {
                curr = curr -> left;
            }
        }

        curr = root;
        while(curr != NULL) {
            if(curr -> key > key) {
                suc = curr;
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }

        return {pre, suc};
    }
};
