class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        vector<int> v;
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt = 0;
            }
        }
        v.push_back(cnt);
        int ans = INT_MIN;
        for(int i = 0; i < v.size(); i++) {
            ans = max(ans, v[i]);
        }
        return ans;
    }
};
