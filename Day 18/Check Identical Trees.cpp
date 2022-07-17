bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
   
    //base case
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 == NULL && root2 != NULL) {
        return false;
    }
    if(root1 != NULL && root2 == NULL) {
        return false;
    }

    bool left = identicalTrees(root1 -> left, root2 -> left);
    bool right = identicalTrees(root1 -> right, root2 -> right);
    bool value = root1 -> data == root2 -> data;

    if(left && right && value) {
        return true;
    }
    else{
        return false;
    }
}
