vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool LTR = true;

    while(!q.empty()) {

        int size = q.size();
        vector<int> temp(size);

        for(int i = 0; i < size; i++) {

            BinaryTreeNode<int>* frontNode = q.front();
            q.pop();

            int index = LTR ? i : size - i - 1;
            temp[index] = frontNode -> data;

            if(frontNode -> left) {
                q.push(frontNode -> left);
            }
            if(frontNode -> right) {
                q.push(frontNode -> right);
            }
        }

        LTR = !LTR;

        for(int i = 0; i < size; i++) {
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
