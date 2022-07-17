#include<bits/stdc++.h>
TreeNode<int>* solve(vector<int>& in, vector<int>& post, int &postIndex, int startIndex, int endIndex, int n, map<int,int> &mp) {
    //base case
    if(postIndex < 0 || startIndex > endIndex) {
        return NULL;
    }

    int element = post[postIndex--];
    TreeNode<int>* root = new TreeNode<int>(element);
    int position = mp[element];

    root -> right = solve(in, post, postIndex, position+1, endIndex, n, mp);
    root -> left = solve(in, post, postIndex, startIndex, position-1, n, mp);

    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int n = inOrder.size();
    int postIndex = n-1;
    int startIndex = 0;
    int endIndex = n-1;
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mp[inOrder[i]] = i;
    }

    TreeNode<int>* ans = solve(inOrder, postOrder, postIndex, startIndex, endIndex, n, mp);

    return ans;
}
