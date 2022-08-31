class Solution {
public:
    double myPow(double x, int n) {
        
        long long power = n;
        double ans = 1.0;
        
        if(n < 0) {
            power *= -1; 
        }
        
        while(power) {
            
            if(power%2 == 0) {
                x *= x;
                power /= 2;
            }
            else {
                ans *= x;
                power -= 1;
            }
        }
        
        if(n < 0) {
            ans = 1.0/ans;
        }
        
        return ans;
    }
};
