#include<algorithm>
void solve(BinaryTreeNode<int> *root, vector<int> &inorder) {
    //root case
    if(root == NULL) {
        return;
    }
    
    solve(root -> left, inorder);
    
    inorder.push_back(root -> data);
   
    solve(root -> right, inorder);
}

bool validateBST(BinaryTreeNode<int> *root) {
    
    vector<int> inorder;
    solve(root, inorder);
    
    vector<int> temp = inorder;
    sort(temp.begin(), temp.end());
    
    if(temp == inorder) {
        return true;
    }
    else{
        return false;
    }
}
