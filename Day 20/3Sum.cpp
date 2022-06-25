class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n < 3) {
            return triplets;
        }
        if(nums[0] > 0) {
            return triplets;
        }
        
        for(int i = 0; i<n ;i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1, k = n-1;

         while(j < k) {
             
             if(nums[i] + nums[j] + nums[k] == 0) {
                 triplets.push_back({nums[i], nums[j], nums[k]});
                 
                 while(j<k && nums[j] == nums[j+1]) {
                     j++;
                 }
                 while(j<k && nums[k] == nums[k-1]) {
                     k--;
                 }
                 j++;
                 k--;
             }
             else if(nums[i] + nums[j] + nums[k] > 0) {
                 k--;
             }
             else{
                 j++;
             }
          }
       }
        return triplets;
    }
};
