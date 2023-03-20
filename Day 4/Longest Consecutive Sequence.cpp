class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }
        
        int ans = 0;        
        for(auto it: nums) {
            if(!st.count(it-1)) {
                int len = 1;
                
                while(st.count(it+len)) {
                    len++;
                }
                
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
};
