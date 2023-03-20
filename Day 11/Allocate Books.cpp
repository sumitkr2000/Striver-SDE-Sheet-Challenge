class Solution {
private:
   bool isPossible(vector<int> A, int n, int B, int mid) {

       int student = 1, pageCount = 0;

       for(int i = 0; i < n; i++) {
           if(pageCount + A[i] <= mid) {
               pageCount += A[i];
           }
           else {
               student += 1;
               pageCount = A[i];
               if(A[i] > mid || student > B) {
                   return false;
               }
           }
       }
       return true; 
   }

public:
   int books(vector<int> &A, int B) {

       int n = A.size();

       if(B > n) {
           return -1;
       }

       int s = A[0];
       int e = 0;

       for(int i = 0; i < n; i++) {
           e += A[i];
       }

       int ans = -1;

       while(s <= e) {
           int mid = s + (e - s)/2;

           if(isPossible(A, n, B, mid)) {
               ans = mid;
               e = mid-1;
           }
           else {
               s = mid+1;
           }
       }
       return ans;
   }
};
