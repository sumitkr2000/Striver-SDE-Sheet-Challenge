class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        long ans = 1;
        
        while(!q.empty()) {
            int size = q.size();
            long mini = q.front().second;
            long maxi = q.back().second;
            ans = max(ans, maxi-mini+1);
            
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                
                long index = p.second - mini;
                
                if(p.first -> left) {
                    q.push({p.first -> left, 2*index+1});
                }
                if(p.first -> right) {
                    q.push({p.first -> right, 2*index+2});
                }
            }
        }
        return ans;
    }
};
