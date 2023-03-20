class Solution {
private:
    void solve(int i, int target, vector<int> &candidates, vector<int> &op, vector<vector<int>> &ans) {

        if(i == candidates.size()) {
            if(target == 0) {
                ans.push_back(op);
            }
            return;
        }
                
        solve(i+1, target, candidates, op, ans);
        
        if(candidates[i] <= target) {
            op.push_back(candidates[i]);
            solve(i, target-candidates[i], candidates, op, ans);
            op.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> op;
        
        solve(0, target, candidates, op, ans);
        return ans;
    }
};
