class nodeInfo {
public:
    int maxi;
    int mini;
    int sum;
};

class Solution {
private:
    nodeInfo solve(TreeNode* root, int &ans) {
      
        if(root == NULL) {
            return {INT_MIN, INT_MAX, 0};
        }
        
        nodeInfo left = solve(root -> left, ans);
        nodeInfo right = solve(root -> right, ans);
        
        if(root -> val > left.maxi && root -> val < right.mini) {
            ans = max(ans, root -> val + left.sum + right.sum);
            return {max(root -> val, right.maxi), min(root -> val, left.mini), root -> val + left.sum + right.sum};
        }
        
        return {INT_MAX, INT_MIN, 0};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
