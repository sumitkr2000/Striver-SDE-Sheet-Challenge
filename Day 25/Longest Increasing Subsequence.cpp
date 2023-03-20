class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // Approach: 1
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
        /*// Approach: 2(Binary Search)
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
        */
        
        /*// For printing LIS
        vector<int> dp(n, 1), cont(n);
        int ans = 1, lastIndex = 0;
        
        for(int i = 0; i < n; i++) {
            cont[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    cont[i] = j;
                }
            }
            if(dp[i] > ans) {
                ans = dp[i];
                lastIndex = i;
            }
        }
              
        vector<int> v;
        v.push_back(nums[lastIndex]);
        
        while(cont[lastIndex] != lastIndex) {
            lastIndex = cont[lastIndex];
            v.push_back(nums[lastIndex]);
        }
        
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            cout<<v[i]<<" ";
        }
        */
    }
};
