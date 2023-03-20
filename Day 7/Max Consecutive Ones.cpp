class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                int cnt = 0;
                while(i != n && nums[i] != 0) {
                    cnt++;
                    i++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
