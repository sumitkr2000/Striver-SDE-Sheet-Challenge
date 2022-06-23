class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> v;
        
        int i = 0;
        int j = 0;
        
        while(i<m && j<n) {
            if(nums1[i] < nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m) {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n) {
            v.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        nums1 = v;
    }
};
