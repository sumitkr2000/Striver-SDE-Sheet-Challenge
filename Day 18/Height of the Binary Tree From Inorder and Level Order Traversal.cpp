int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	
    if(root == NULL) {
        return 0;
    }

    //recursive call
    int left = maxDepth(root -> left);
    int right = maxDepth(root -> right);

    return 1 + max(left,right);
}
