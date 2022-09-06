class Solution {
private:
    void solve(int i, vector<int> &candidates, int target, vector<int> &op, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(op);
            return;
        }
        
        for(int j = i; j < candidates.size(); j++) {
            if(j != i && candidates[j] == candidates[j-1]) {
                continue;
            }
            if(candidates[j] > target) {
                break;
            }
            
            op.push_back(candidates[j]);
            solve(j + 1, candidates, target - candidates[j], op, ans);
            op.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        
        solve(0, candidates, target, op, ans);
        
        return ans;
    }
};
