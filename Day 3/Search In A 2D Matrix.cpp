class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();       
        int s = 0,  e = n * m - 1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;  
            int element = matrix[mid/m][mid%m];
            
            if(element == target) {
                return 1;
            }
            else if(element < target) {
                s = mid + 1;
            }
            else {
                e = mid-1;
            }
        }
        return 0;
    }
};
