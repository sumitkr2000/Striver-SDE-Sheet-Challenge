class Solution {
private:
    TreeNode* solve(int &i, int s, int e, vector<int> &preorder, 
                    vector<int> &inorder, unordered_map<int, int> &mp) {
        //base case
        if(i == inorder.size() || s > e) {
            return NULL;
        }
        
        int pos = mp[preorder[i]];
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root -> left = solve(i, s, pos-1, preorder, inorder, mp);
        root -> right = solve(i, pos+1, e, preorder, inorder, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        int i = 0;
        
        TreeNode* root = solve(i, 0, n-1, preorder, inorder, mp);
        return root;
    }
};
