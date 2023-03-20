class Solution {
public:
    int floorInBST(TreeNode * root, int X) {

        int ans = -1;
        
        while(root != NULL) {
            if(root -> val > X) {
                root = root -> left;
            }
            else if(root -> val < X) {
                ans = root -> val;
                root = root -> right;
            }
            else {
                return X;
            }
        }
        return ans;
    }
};
