#include<map>
int findMajorityElement(int arr[], int n) {
  map<int, int> mp;

  for(int i = 0; i < n; i++) {
      mp[arr[i]]++;
  }

  for(auto i: mp) {
      if(i.second > n/2) {
          return i.first;
          break;
      }
  }
  return -1;
}
