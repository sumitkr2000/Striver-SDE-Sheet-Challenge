class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            root = root -> left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        TreeNode* temp = top -> right;
        
        while(temp != NULL) {
            st.push(temp);
            temp = temp -> left;
        }
        
        return top -> val;
    }
    
    bool hasNext() {
        return st.size() != 0;
    }
};
