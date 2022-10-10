class BSTIterator {
public:
    stack<TreeNode*> st;
    bool isPrev;
    
    BSTIterator(TreeNode* root, bool flag) {
        isPrev = flag;
        TreeNode* curr = root;
        
        while(curr != NULL) {
            st.push(curr);
            curr = isPrev ? curr -> right : curr -> left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        TreeNode* temp = isPrev ? top -> left : top -> right;
        
        while(temp != NULL) {
            st.push(temp);
            temp = isPrev ? temp -> right : temp -> left;
        }
        
        return top -> val;
    } 
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator low(root, false);
        BSTIterator high(root, true);
        
        int i = low.next(), j = high.next();
        
        while(i < j) {
            if(i + j == k) {
                return true;
            }
            else if(i + j < k) {
                i = low.next();
            }
            else {
                j = high.next();
            }
        }
        return false;
    }
};
