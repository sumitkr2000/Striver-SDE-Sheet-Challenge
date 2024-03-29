class Solution {
public:
    vector<int> zigZagTraversal(TreeNode* root) {

        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool left = 1;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                int index = left ? i : size - i - 1;
                temp[index] = frontNode -> data;

                if(frontNode -> left) {
                    q.push(frontNode -> left);
                }
                if(frontNode -> right) {
                    q.push(frontNode -> right);
                }
            }

            left = !left;
            for(int i = 0; i < size; i++) {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};
