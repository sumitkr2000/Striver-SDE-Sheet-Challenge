#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);

  for(int i = n-1; i >= 0; i--) {
    int curr = arr[i];

    while(s.top() != -1 && s.top() <= curr) {
      s.pop();
    }
    ans[i] = s.top();
    s.push(curr);
  }
  return ans;

}
