class Solution {
private:
    bool solve(TreeNode* root1, TreeNode* root2) {
        //base case
        if(root1 == NULL && root2 == NULL) {
            return true;
        }
        
        if(root1 == NULL || root2 == NULL || root1 -> val != root2 -> val) {
            return false;
        }
        
        bool first = solve(root1 -> left, root2 -> right);
        bool second = solve(root1 -> right, root2 -> left);
        
        return first & second;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        
        return solve(root -> left, root -> right);
    }
};
