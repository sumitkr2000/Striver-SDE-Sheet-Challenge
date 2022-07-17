#include<bits/stdc++.h>
TreeNode<int>* solve(vector<int>& in, vector<int>& pre, int &preIndex,
                int startIndex, int endIndex, int n, map<int,int> &mp) {

    //base case
    if(preIndex == n || startIndex > endIndex) {
        return NULL;
    }

    int element = pre[preIndex++];
    TreeNode<int>* root = new TreeNode<int>(element);
    int position = mp[element];

    root -> left = solve(in, pre, preIndex, startIndex, position-1, n, mp);
    root -> right = solve(in, pre, preIndex, position+1, endIndex, n, mp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int n = preorder.size();
    int preIndex = 0;
    int startIndex = 0;
    int endIndex = n-1;
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mp[inorder[i]] = i;
    }

    TreeNode<int>* ans = solve(inorder, preorder, preIndex, startIndex, endIndex, n, mp);

    return ans;
}
