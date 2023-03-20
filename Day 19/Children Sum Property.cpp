class Solution {
public:
    void changeTree(TreeNode<int>* root) {

        if(root == NULL) {
            return;
        }

        int childSum = 0;
        if(root -> left) {
            childSum += root -> left -> data;
        }
        if(root -> right) {
            childSum += root -> right -> data;
        }

        if(root -> data <= childSum) {
            root -> data = childSum;
        }
        else {
            if(root -> left) {
                root -> left -> data = root -> data;
            }
            if(root -> right) {
                root -> right -> data = root -> data;
            }
        }

        changeTree(root -> left);
        changeTree(root -> right);

        int sum = 0;
        if(root -> left) {
            sum += root -> left -> data;
        }
        if(root -> right) {
            sum += root -> right -> data;
        }
        if(root -> left || root -> right) {
            root -> data = sum;
        }
    }
};
