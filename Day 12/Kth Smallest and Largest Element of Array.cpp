#include<algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{   
    sort(arr.begin(), arr.end());
    vector<int> ans;   
    
    ans.push_back(arr[k-1]);
    ans.push_back(arr[n-k]);
    
    return ans;
}
