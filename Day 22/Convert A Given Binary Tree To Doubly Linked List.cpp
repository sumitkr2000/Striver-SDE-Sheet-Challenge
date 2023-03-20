class Solution {
private:
    void solve(TreeNode* root, TreeNode* &head, TreeNode* &prev) {

        if(root == NULL) {
            return;
        }

        solve(root -> left, head, prev);

        if(head == NULL) {
            head = root;
        }
        else {
            root -> left = prev;
            prev -> right = root;
        }
        prev = root;
        solve(root -> right, head, prev);
    }

public:
    TreeNode* BTtoDLL(TreeNode* root) {

        TreeNode *head = NULL, *prev = NULL;

        solve(root, head, prev);
        return head;
    }
};
