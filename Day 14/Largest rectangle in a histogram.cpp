class Solution {
private: 
    void solve(vector<int> &arr, int n, vector<int> &next, vector<int> &prev) {

        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        //Approach 1
        vector<int> next(n, -1), prev(n, -1);
        solve(heights, n, next, prev);
        
        int area = 0;
        
        for(int i = 0; i < n; i++) {
            if(next[i] == -1) {
                next[i] = n;
            }
            
            int currArea = heights[i] * (next[i] - prev[i] - 1);
            area = max(area, currArea);
        }
        return area;
        
        
        /*//Approach 2
        stack<int> st;
        int area = 0;
        
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[i] <= heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = i;
                if(!st.empty()) {
                    width = i - st.top() - 1;
                }
                area = max(area, height*width);
            }
            st.push(i);
        }
        return area;
        */
    }
};
