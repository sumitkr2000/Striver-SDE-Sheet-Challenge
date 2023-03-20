class Solution {
private:
    TreeNode* solve(int &i, int s, int e, vector<int> &in, vector<int> &post, unordered_map<int, int> &mp) {

        if(i < 0 || s > e) {
            return NULL;
        }
        
        int pos = mp[post[i]];
        TreeNode* root = new TreeNode(post[i--]);
        
        root -> right = solve(i, pos+1, e, in, post, mp);
        root -> left = solve(i, s, pos-1, in, post, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        int i = n-1;
        
        TreeNode* root = solve(i, 0, n-1, inorder, postorder, mp);
        return root;
    }
};
