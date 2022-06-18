bool searchInBST(BinaryTreeNode<int> *root, int x) {
  
    //Approach 1 using recursion S.C. = O(N)
    if(root == NULL) {
        return false;
    }
    
    if(root -> data == x) {
        return true;
    }
    
    if(x < root -> data) {
        return searchInBST(root -> left, x);
    }
    else{
        return searchInBST(root -> right, x);
    }
    return false;
    
    /
    //Approach 2 using iteration S.C. =O(1);
    Node* temp = root;
    while(temp != NULL) {
        if(temp -> data == x) {
            return true;
        }
        
        if(x < temp -> data) {
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}
