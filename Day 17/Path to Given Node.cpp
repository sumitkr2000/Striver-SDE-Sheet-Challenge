void helper(TreeNode* A, int B, vector<int> &ans) {
     //base case
    if(A == NULL) {
        return;
    }
    
    ans.push_back(A -> val);
    
    if(A -> val == B) {
        return;
    }
    
    helper(A -> left, B, ans);
    helper(A -> right, B, ans);
    
    if(ans.back() != B) {
        ans.pop_back();
    }
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> ans;
    helper(A, B, ans);
    
    return ans;
}
