class Solution {
private:
    bool solve(TreeNode* root, long mini, long maxi) {
        
        if(root == NULL) {
            return true;
        }
        
        if(root -> val > mini && root -> val < maxi) {
            bool left = solve(root -> left, mini, root -> val);
            bool right = solve(root -> right, root -> val, maxi);
            
            return left & right;
        }
        return false;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
