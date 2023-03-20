class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int s = 0, e = nums.size() - 2;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(nums[mid] == nums[mid^1]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return nums[s];
    }
};
