class Solution {
private:
    bool isLeaf(TreeNode* root) {
        return (root -> left == NULL && root -> right == NULL);
    }

    void traverseLeft(TreeNode* root, vector<int> &ans) {

        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(!isLeaf(curr)) {
                ans.push_back(curr -> data);
            }
            if(curr -> left) {
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }
    }

    void traverseLeaf(TreeNode* root, vector<int> &ans) {

        if(isLeaf(root)) {
            ans.push_back(root -> data);
            return;
        }

        if(root -> left) {
            traverseLeaf(root -> left, ans);
        }
        if(root -> right) {
            traverseLeaf(root -> right, ans);
        }
    }

    void traverseRight(TreeNode* root, vector<int> &ans) {

        TreeNode* curr = root;
        vector<int> temp;
        
        while(curr != NULL) {
            if(!isLeaf(curr)) {
                temp.push_back(curr -> data);
            }
            if(curr -> right) {
                curr = curr -> right;
            }
            else {
                curr = curr -> left;
            }
        }
        
        for(int i = temp.size()-1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> traverseBoundary(TreeNode* root){

        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        if(!isLeaf(root)) {
            ans.push_back(root -> data);
        }

        traverseLeft(root -> left, ans);
        traverseLeaf(root, ans);
        traverseRight(root -> right, ans);

        return ans;
    }
};
