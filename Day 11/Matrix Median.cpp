int getMedian(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int low = 0;
    int high = 1e9;
    
    while(low <= high) {
        int mid1 = low + (high - low)/2;
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            int s = 0, e = m-1;
            
            while(s <= e) {
                int mid2 = s + (e - s)/2;
                
                if(matrix[i][mid2] <= mid1) {
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
