void inOrder(BinaryTreeNode<int> *root, vector<int> &in) {

    if(root == NULL) {
        return;
    }

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}

//peworder traversal using recusrison
void preOrder(BinaryTreeNode<int> *root, vector<int> &pre) {

    if(root == NULL) {
        return;
    }

    pre.push_back(root -> data);
    preOrder(root -> left, pre);
    preOrder(root -> right, pre);
}

//postorder traversal using recusrison
void postOrder(BinaryTreeNode<int> *root, vector<int> &post) {

    if(root == NULL) {
        return;
    }

    postOrder(root -> left, post);
    postOrder(root -> right, post);
    post.push_back(root -> data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    
    vector<int> in;
    inOrder(root, in);
    
    vector<int> pre;
    preOrder(root, pre);
    
    vector<int> post;
    postOrder(root, post);
    
    vector<vector<int>> ans;
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
   
    return ans;
}
