// Boyer Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int ans = 0;
        
        for(auto it: nums) {
            if(cnt == 0) {
                ans = it;
            }
            
            if(it == ans) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return ans;
    }
};
