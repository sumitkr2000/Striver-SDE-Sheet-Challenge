class Solution {
public:
    vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

        vector<int> in, pre, post;
        vector<vector<int>> ans;
        stack<pair<BinaryTreeNode<int>*, int>> st;
        st.push({root, 1});

        if(root == NULL) {
            return ans;
        }

        while(!st.empty()) {
            if(st.top().second == 1) {
                pre.push_back(st.top().first -> data);
                st.top().second++;

                if(st.top().first -> left) {
                    st.push({st.top().first -> left, 1});
                }
            }
            else if(st.top().second == 2) {
                in.push_back(st.top().first -> data);
                st.top().second++;

                if(st.top().first -> right) {
                    st.push({st.top().first -> right, 1});
                }
            }
            else {
                post.push_back(st.top().first -> data);
                st.pop();
            }
        }

        ans.push_back(in);
        ans.push_back(pre);
        ans.push_back(post);
        return ans;
    }
};
