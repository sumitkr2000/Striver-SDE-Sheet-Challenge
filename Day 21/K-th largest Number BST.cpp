int solve(TreeNode<int>* root, int &k) {
    //base case
    if(root == NULL) {
        return -1;
    }

    int right = solve(root -> right, k);
    if(right != -1) {
        return right;
    }

    k--;
    if(k == 0) {
        return root -> data;
    }

    return solve(root -> left, k);  
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = solve(root, k);   
    return ans;
}
