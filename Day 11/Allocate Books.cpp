bool ispossible(int n, int m, long long int mid,vector<int> time) {

   int daycount = 1;
   long long int timecount = 0;

   for(int i = 0; i < m; i++) {
       if(timecount + time[i] <= mid) {
           timecount += time[i];
       }
       else {
           daycount++;
           if(daycount > n || time[i] > mid) {
               return false;
           }
           timecount = time[i];
       }
   }
   return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
   long long int s = 0;
   long long int sum = 0;
   long long int ans = -1;

   for(int i = 0; i < m; i++) {
       sum += time[i];
   }

   long long int e = sum;
   long long int mid = s+(e-s)/2;

   while(s <= e) {

   if(ispossible(n, m, mid, time)) {
       ans = mid;
       e = mid-1;
   }
   else {
       s = mid+1;
   }
       mid = s+(e-s)/2;
   }
   return ans;
}
