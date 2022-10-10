void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev) {
    //base case
    if(root == NULL) {
        return;
    }
    
    solve(root -> left, head, prev);
    
    if(head == NULL) {
        head = root;
    }
    else {
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;
    solve(root -> right, head, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    BinaryTreeNode<int>* head = NULL;    
    BinaryTreeNode<int>* prev = NULL;
    
    solve(root, head, prev);
    return head;
}
