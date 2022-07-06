void singleTraversal(BinaryTreeNode<int> *root, vector<int> &in, vector<int> &pre, vector<int> &post) {

    if(root == NULL) {
        return;
    }

    pre.push_back(root -> data);
    singleTraversal(root -> left, in, pre, post);
    in.push_back(root -> data);
    singleTraversal(root -> right, in, pre, post);
    post.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    
    vector<int> in;    
    vector<int> pre;    
    vector<int> post;
    
    singleTraversal(root, in, pre, post);
    
    vector<vector<int>> ans;
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
   
    return ans;
}
