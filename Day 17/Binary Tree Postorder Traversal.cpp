class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        stack<TreeNode*> st;
        st.push(root);  
        while(!st.empty()) {
            
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr -> val);
            
            if(curr -> left != NULL) {
                st.push(curr -> left);
            }
            if(curr -> right != NULL) {
                st.push(curr -> right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
