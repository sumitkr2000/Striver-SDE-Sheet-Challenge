class Solution {
private:
    bool isPossible(vector<int> &stalls, int n, int k, int mid) {
        
        int cnt = 1, last = stalls[0];
        for(int i = 1; i < n; i++) {
            if(stalls[i] - last >= mid) {
                cnt++;
                last = stalls[i];
                
                if(cnt == k) {
                    return true;
                }
            }
        }
        return false;
    }
	
public:
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int s = 1, e = stalls[n-1] - stalls[0];
        int ans = 0;
        
        while(s <= e) {
            int mid = s + (e - s)/2;
            
            if(isPossible(stalls, n, k, mid)) {
                ans = mid;
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return ans;
    }
};
