class Solution
{
private:
    void solve(int i, int sum, vector<int> &arr, int N, vector<int> &ans) {
        //base case
        if(i == N) {
            ans.push_back(sum);
            return;
        }
        
        solve(i+1, sum, arr, N, ans);
        solve(i+1, sum+arr[i], arr, N, ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0, 0, arr, N, ans);
        return ans;
    }
};
