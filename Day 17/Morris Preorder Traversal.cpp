class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      
        TreeNode* curr = root;
        vector<int> ans;
        
        while(curr != NULL) {
            if(curr -> left) {
                TreeNode* temp = curr -> left; 
                while(temp -> right != NULL && temp -> right != curr) {
                    temp = temp -> right;
                }
                if(temp -> right) {
                    temp -> right = NULL;
                    curr = curr -> right;
                }
                else {
                    ans.push_back(curr -> val);
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
            else {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
        }
        return ans;
    }
};
