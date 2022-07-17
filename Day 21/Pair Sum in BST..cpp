void solve(BinaryTreeNode<int>* root, vector<int> &inorder) {
    //base case
    if(root == NULL) {
        return;
    }

    solve(root -> left, inorder);
    inorder.push_back(root -> data);
    solve(root -> right, inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    
    solve(root, inorder);

    int i = 0;
    int j = inorder.size()-1;

    while(i < j) {
        if(inorder[i] + inorder[j] == k) {
            return true;
        }
        else if(inorder[i] + inorder[j] > k) {
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}
