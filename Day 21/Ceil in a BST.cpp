class Solution {
public:
    int findCeil(TreeNode* root, int x){

        int ans = -1;
        
        while(root != NULL) {
            if(root -> data > x) {
                ans = root -> data;
                root = root -> left;
            }
            else if(root -> data < x) {
                root = root -> right;
            }
            else {
                return root -> data;
            }
        }
        return ans;
    }
};
