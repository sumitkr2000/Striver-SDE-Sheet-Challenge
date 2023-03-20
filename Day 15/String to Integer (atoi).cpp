class Solution {
private:
    bool isDigit(char digit) {
        return digit >= '0' && digit <= '9';
    }
    
public:
    int myAtoi(string s) {
        
        int n = s.size();
        int i = 0, sign = 1, ans = 0;
        
        while(i < n && s[i] == ' ') {
            i++;
        }
        
        if(s[i] == '+') {
            i++;
        }
        else if(s[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(i < n && isDigit(s[i])) {
            
            int digit = s[i] - '0';
            
            if(ans > (INT_MAX - digit) / 10) {
                if(sign == 1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        
        return ans * sign;
    }
};
