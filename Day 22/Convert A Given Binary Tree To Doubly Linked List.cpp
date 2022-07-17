BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    BinaryTreeNode<int>* curr = root;
        
    while(curr != NULL) {

        if(curr -> left != NULL) {
            BinaryTreeNode<int>* pred = curr -> left;

            while(pred -> right != NULL) {
                pred = pred -> right;
            }

            pred -> right = curr -> right;
            curr -> right = curr -> left;
        }
        curr = curr -> right;
    }
}
