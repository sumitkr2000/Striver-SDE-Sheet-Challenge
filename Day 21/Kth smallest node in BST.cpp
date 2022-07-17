int inorder(TreeNode<int>* root, int &k) {
    //base case
    if(root == NULL) {
        return -1;
    }

    int left = inorder(root -> left, k);
    if(left != -1) {
        return left;
    }

    k--;
    if(k == 0) {
        return root -> data;
    }

    return inorder(root -> right, k);  
}

int kthSmallest(TreeNode<int> *root, int k)
{
	int ans = inorder(root, k);   
    return ans;
}
