class Solution {
private:
     pair<int,int> solve(TreeNode* root) {
      
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(max(op1, op2), op3);
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        return solve(root).first-1;
    }
};
