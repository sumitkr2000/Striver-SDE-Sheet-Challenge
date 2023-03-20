class Solution {
private:
    void solve(int i, vector<int> &nums, vector<int> &op, vector<vector<int>> &ans) {
        
        ans.push_back(op);
        
        for(int j = i; j < nums.size(); j++) {
            if(j != i && nums[j] == nums[j-1]) {
                continue;
            }
            op.push_back(nums[j]);
            solve(j + 1, nums, op, ans);
            op.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> op;
        sort(nums.begin(), nums.end());
        solve(0, nums, op, ans);
        
        return ans;
    }
};
