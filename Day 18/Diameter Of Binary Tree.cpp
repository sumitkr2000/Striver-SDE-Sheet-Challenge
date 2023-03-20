class Solution {
private:
    int solve(TreeNode* root, int &ans) {
        
        if(root == NULL) {
            return 0;
        }

        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);
        
        ans = max(ans, left + right);

        return 1 + max(left, right);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
