void solve(BinaryTreeNode<int> *node, int x, int &ans) {
    if(node == NULL) {
        return;
    }
    
    if(node -> data == x) {
        ans = node -> data;
        return;
    }
    
    if(node -> data > x) {
        ans = node -> data;
        solve(node -> left, x, ans);
    }
    if(node -> data < x) {
        solve(node -> right, x, ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    
    solve(node, x, ans);
    return ans;
}
