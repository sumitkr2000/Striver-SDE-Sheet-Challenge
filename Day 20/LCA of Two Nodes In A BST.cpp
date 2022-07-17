TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    //Approach 1 using iteration
    while(root != NULL) {
        if(root -> data > P -> data && root -> data > Q -> data) {
            root = root -> left;
        }
        else if(root -> data < P -> data && root -> data < Q -> data) {
            root = root -> right;
        } 
        else{
            return root;
        }     
    }
    
    /*
    //Approach 2 using recursion
	//base case
    if(root == NULL) {
        return NULL;
    }
    
    if(root -> data > P -> data && root -> data > Q -> data) {
        return LCAinaBST(root -> left, P, Q);
    }
    
    if(root -> data < P -> data && root -> data < Q -> data) {
        return LCAinaBST(root -> right, P, Q);
    } 
    return root;
    */
}
