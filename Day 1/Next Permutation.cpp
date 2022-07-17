#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
   int changeIdx = -1;
   for(int i = n-2; i >= 0; i--) {
       if(permutation[i] < permutation[i+1]) {
           changeIdx = i;
            break;
       }
   }

   if(changeIdx == -1) {
       sort(permutation.begin(), permutation.end());
       return permutation;
   }

   int firstBigger = -1;
   for(int i = n-1; i > changeIdx; i--) {
       if(permutation[i] > permutation[changeIdx]) {
           firstBigger = i;
           break;
       }
   }

   swap(permutation[changeIdx], permutation[firstBigger]);
   reverse(permutation.begin() + changeIdx + 1, permutation.end());

   return permutation;
}
