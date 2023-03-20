class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode* temp = root;
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(true) {
            if(temp != NULL) {
                st.push(temp);
                temp = temp -> left;
            }
            else{
                if(st.empty()) break;
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                temp = temp -> right;
            }
        }
        return ans;
    }
};
