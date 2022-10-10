class Solution {
private:
    TreeNode* solve(int s, int e, vector<int> &nums) {
        //base case
        if(s > e ) {
            return NULL;
        }
        
        int mid = (s + e)/2;        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root -> left = solve(s, mid-1, nums);
        root -> right = solve(mid+1, e, nums);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(0, nums.size()-1, nums);
    }
};
