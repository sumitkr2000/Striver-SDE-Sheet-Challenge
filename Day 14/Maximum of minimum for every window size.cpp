class Solution {
public:
    vector<int> maxMinWindow(vector<int> a, int n) {

        vector<int> nse(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[i] < a[st.top()]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }
        
        vector<int> pse(n, -1);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && a[i] < a[st.top()]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(n, INT_MIN);

        for(int i = 0; i < n; i++) {
            int ind = nse[i] - pse[i] - 2;
            ans[ind] = max(ans[ind], a[i]);
        }

        for(int i = n-2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }

        return ans;
    }
};
