class Solution {
public:
    vector<int> solve(vector<int> &A, vector<int> &B, int C) {

        int n = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({A[n-1]+B[n-1], {n-1, n-1}});

        set<pair<int, int>> st;
        st.insert({n-1, n-1});

        vector<int> ans;

        while(C > 0) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.first);

            int i = top.second.first;
            int j = top.second.second;

            if(i > 0 && st.find({i-1, j}) == st.end()) {
                pq.push({A[i-1]+B[j], {i-1, j}});
                st.insert({i-1, j});
            }
            if(j > 0 && st.find({i, j-1}) == st.end()) {
                pq.push({A[i]+B[j-1], {i, j-1}});
                st.insert({i, j-1});
            }
            C--;
        }
        return ans;
    }
};
