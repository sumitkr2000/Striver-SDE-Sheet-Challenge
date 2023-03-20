class Solution {
private:
    void solve(int i, vector<int> &nums, vector<vector<int>> &ans) {        

        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        solve(0, nums, ans);

        return ans;
    }
};
