void solve(TreeNode<int> * root, int X, int &ans) {
    if(root == NULL) {
        return;
    }
    
    if(root -> val == X) {
        ans = root -> val;
        return;
    }
    
    if(root -> val > X) {
        solve(root -> left, X, ans);
    }
    if(root -> val < X) {
        ans = root -> val;
        solve(root -> right, X, ans);
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    solve(root, X, ans);
    return ans;
}
