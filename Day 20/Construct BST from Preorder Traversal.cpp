class Solution {
private:
    TreeNode* solve(int &i, vector<int> &pre, int maxi) {
 
        if(i == pre.size() || pre[i] > maxi) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[i++]);
        
        root -> left = solve(i, pre, root -> val);
        root -> right = solve(i, pre, maxi);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        return solve(i, preorder, INT_MAX);
    }
};
