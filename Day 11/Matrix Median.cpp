class Solution {
public:
    int findMedian(vector<vector<int> > &A) {

        int n = A.size(, m = A[0].size();
        int low = 0, high = 1e9;

        while(low <= high) {
            int mid1 = low + (high - low)/2;
            int cnt = 0;

            for(int i = 0; i < n; i++) {
                int s = 0, e = m-1;

                while(s <= e) {
                    int mid2 = s + (e - s)/2;

                    if(A[i][mid2] <= mid1) {
                        s = mid2 + 1;
                    }
                    else {
                        e = mid2 - 1;
                    }
                }
                cnt += s;
            }

            if(cnt <= (n*m)/2) {
                low = mid1 + 1;
            }
            else {
                high = mid1 - 1;
            }
        }
        return low;
    }
};
