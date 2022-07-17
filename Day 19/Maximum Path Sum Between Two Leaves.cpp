#include<bits/stdc++.h>
long long int maxi(TreeNode<int>*root){
    if(root==NULL)return 0;
    long long int a=maxi(root->left)+root->val;
    long long int b=maxi(root->right)+root->val;
    return max(a,b);
}
int leaf(TreeNode<int>*root){
    if(root==NULL){return 0;}
    if(root->left==NULL && root->right==NULL)return 1;
    int a=leaf(root->left);
    int b=leaf(root->right);
    return a+b;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL){
        return -1;
    }
    if(leaf(root)==1)return -1;
    if(root->right==NULL && root->right==NULL)return root->val;
    long long int a=maxi(root->left)+maxi(root->right)+root->val;
    long long int b=findMaxSumPath(root->left);
    long long int c=findMaxSumPath(root->right);
    return max(a,max(b,c));
}
