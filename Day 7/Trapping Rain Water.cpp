class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        //Approach 1: Uisng two pointers
        int i = 0, j = n-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        
        while(i < j) {
            if(height[i] <= height[j]) {
                if(height[i] >= leftMax) {
                    leftMax = height[i];
                }
                else {
                    ans += leftMax - height[i];
                }
                i++;
            }
            else {
                if(height[j] >= rightMax) {
                    rightMax = height[j];
                }
                else {
                    ans += rightMax - height[j];
                }
                j--;
            }
        }
        return ans;
        
        /*//Approach 2: Uisng extra space
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return ans;
        */
    }
};
