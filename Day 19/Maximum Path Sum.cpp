class Solution {
private:
    int solve(TreeNode* root, int &ans) {
        //base case
        if(root == NULL) {
            return 0;
        }
        
        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);
        
        int maxi = max(root -> val, max(left, right) + root -> val);
        
        ans = max(ans, max(maxi, root -> val + left + right));
        
        return maxi;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
