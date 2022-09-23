class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> s1(26, 0), t1(26, 0);
        
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.size(); i++) {
            int index1 = s[i] - 'a';
            s1[index1]++;
            
            int index2 = t[i] - 'a';
            t1[index2]++; 
        }
        
        for(int i = 0; i < 26; i++) {
            if(s1[i] != t1[i]) {
                return false;
            }
        }
        return true;
    }
};
