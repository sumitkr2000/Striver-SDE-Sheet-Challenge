class Solution {
private:
     void solve(TreeNode* root, int &B, vector<int> &ans) {

         if(root == NULL) {
             return;
         }

         ans.push_back(root -> val);

         if(root -> val == B) {
             return;
         }

         solve(root -> left, B, ans);
         solve(root -> right, B, ans);

         if(ans.back() != B) {
             ans.pop_back();
         }
     }

public:
     vector<int> pathToGivenNode(TreeNode* root, int B) {

         vector<int> ans;
         solve(root, B, ans);

         return ans;
     }
};
