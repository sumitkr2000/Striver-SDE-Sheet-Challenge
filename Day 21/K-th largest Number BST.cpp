class Solution {
private:
    void solve(Node* root, int &K, int &ans) {
     
        if(root == NULL) {
            return;
        }
        
        solve(root -> right, K, ans);
        K--;
        if(K == 0) {
            ans = root -> data;
            return;
        }
        
        solve(root -> left, K, ans);
    }
    
public:
    int kthLargest(Node *root, int K) {
        
        int ans;
        solve(root, K, ans);
        return ans;
    }
};
