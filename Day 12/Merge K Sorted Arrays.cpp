class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;    

        for(int i = 0; i < k; i++) {
            pq.push({kArrays[i][0], {i, 0}});
        }

        vector<int> ans;

        while(!pq.empty()) {
            auto top = pq.top();
            ans.push_back(top.first);
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            if(j + 1 < kArrays[i].size()) {
                pq.push({kArrays[i][j+1], {i, j+1}});
            }
        }
        return ans;
    }
};
