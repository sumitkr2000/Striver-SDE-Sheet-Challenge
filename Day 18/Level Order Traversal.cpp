vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {

        BinaryTreeNode<int> *temp = q.front();
        q.pop();

        if(temp == NULL) {
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            ans.push_back(temp -> val);
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
    return ans;
}
