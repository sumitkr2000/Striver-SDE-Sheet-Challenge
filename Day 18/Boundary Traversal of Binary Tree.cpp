void traverseLeft(TreeNode<int>* root, vector<int> &ans) {
    //base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    ans.push_back(root -> data);

    if(root -> left) {
        traverseLeft(root -> left, ans);
    }
    else {
        traverseLeft(root -> right, ans);
    }
}

void traverseLeaf(TreeNode<int>* root, vector<int> &ans) {
    //base case
    if(root == NULL) {
        return;
    }

    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
    }

    if(root -> left) {
        traverseLeaf(root -> left, ans);
    }
    if(root -> right) {
        traverseLeaf(root -> right, ans);
    }
}

void traverseRight(TreeNode<int>* root, vector<int> &ans) {
    //base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    if(root -> right) {
        traverseRight(root -> right, ans);
    }
    else {
        traverseRight(root -> left, ans);
    }
    ans.push_back(root -> data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    
    vector<int> ans;
        
    if(root == NULL) {
        return ans;
    }

    ans.push_back(root -> data);

    //travserse left
    traverseLeft(root -> left, ans);

    //traverse leaf
    //left part of root
    traverseLeaf(root -> left, ans);

    //right part of root
    traverseLeaf(root -> right, ans);

    //traverse right
    traverseRight(root -> right, ans);

    return ans;
}
