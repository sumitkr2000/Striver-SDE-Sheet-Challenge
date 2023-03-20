class Solution {
public:
	vector<int> nextSmaller(vector<int> &A) {

	    int n = A.size();
	    stack<int> st;
	    vector<int> ans(n, -1);

	    for(int i = 0; i < n; i++) {
		while(!st.empty() && A[i] < A[st.top()]) {
		    ans[st.top()] = A[i];
		    st.pop();
		}
		st.push(i);
	    }
	    return ans;
	}
};
