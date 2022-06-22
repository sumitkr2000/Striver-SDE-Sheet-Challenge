class Solution {
private:
    void solve(vector<int>& nums, int i, int &sum, int &ans) {
        
        if(i == nums.size()) {
            return;
        }
        
        sum = sum + nums[i];
        ans = max(ans, sum);
        
        if(sum < 0) {
            sum = 0;
        }
            
        solve(nums, i+1, sum, ans);    
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int ans = INT_MIN;
        int i = 0;
        
        solve(nums, i, sum, ans);
        return ans;
    }
};
