class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(nums[0] > 0) {
            return ans;
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i+1, k = n-1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j+1]) {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};
