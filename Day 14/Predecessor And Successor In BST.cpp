pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred = -1;
    int succ = -1;
    
    BinaryTreeNode<int>* temp = root;
    while(temp -> data != key) {
        if(key > temp -> data) {
            pred = temp -> data;
            temp = temp -> right;
        }
        else{
            succ = temp -> data;
            temp = temp -> left;
        }
    }
    
    BinaryTreeNode<int>* leftt = temp -> left;
    while(leftt != NULL) {
        pred = leftt -> data;
        leftt = leftt -> right;
    }
    
    BinaryTreeNode<int>* rightt = temp -> right;
    while(rightt != NULL) {
        succ = rightt -> data;
        rightt = rightt -> left;
    }
    
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
