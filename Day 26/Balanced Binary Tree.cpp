class Solution {
private:
    pair<bool,int> solve(TreeNode* root) {
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = solve(root -> left);
        pair<bool,int> right = solve(root -> right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return solve(root).first;
    }
};
