#include<bits/stdc++.h>>
TreeNode<int>* solve(vector<int> &preOrder, int &i, int maxi) {
    //base case
    if((i >= preOrder.size()) || (preOrder[i] > maxi)) {
        return NULL;
    }

    TreeNode<int>* root = new TreeNode<int>(preOrder[i++]);

    root -> left = solve(preOrder, i, root -> data);
    root -> right = solve(preOrder, i , maxi);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int maxi = INT_MAX; 
    int i = 0;

    return solve(preOrder, i, maxi);  
}
