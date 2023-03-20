class Solution {
public:
    vector<int> dNums(vector<int> &A, int B) {

        vector<int> ans;
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        while(i <= A.size()-B && j < A.size()) {
            mp[A[j]]++;

            if(j-i >= B) {
                mp[A[i]]--;
                if(mp[A[i]] == 0) {
                    mp.erase(A[i]);
                }
                i++;
            }

            if(j >= B-1) {
               ans.push_back(mp.size());
            }
            j++;
        }
        return ans;
    }
};
