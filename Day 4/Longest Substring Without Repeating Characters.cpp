class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = 0;
        
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()) {
                i = max(i, mp[s[j]] + 1);
            }
            ans = max(ans, (j-i+1));
            mp[s[j]] = j;
            j++;
        }
        return ans;
    }
};
