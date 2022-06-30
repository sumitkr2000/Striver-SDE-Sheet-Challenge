void solve(Node* root, int lvl, vector<int> &ans) {
    //base case
    if(root == NULL) {
        return;
    }
    
    if(lvl == ans.size()) {
        ans.push_back(root -> data);
    }
    
    solve(root -> left, lvl+1, ans);
    solve(root -> right, lvl+1, ans);
}

vector<int> leftView(Node *root)
{
   int lvl = 0;
   vector<int> ans;
   
   solve(root, lvl, ans);
   
   return ans;
}
