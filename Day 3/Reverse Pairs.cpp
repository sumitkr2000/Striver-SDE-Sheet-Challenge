class Solution {
private:
    int merge(int s, int mid, int e, vector<int> &nums) {
        
        int cnt = 0;
        int j = mid+1;
        
        for(int i = s; i <= mid; i++) {
            while(j <= e && nums[i] > 2LL*nums[j]) {
                j++;
            }
            cnt += (j - (mid+1));
        }
        
        vector<int> temp;
        int i = s;
        j = mid+1;
        while(i <= mid && j <= e) {
            if(nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i++]);
        }
        while(j <= e) {
            temp.push_back(nums[j++]);
        }
        
        for(i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
        return cnt;
    }
    
    int mergeSort(int s, int e, vector<int> &nums) {
        
        int invCnt = 0;
        if(s < e) {
            int mid = s + (e-s)/2;
            
            invCnt += mergeSort(s, mid, nums);
            invCnt += mergeSort(mid+1, e, nums);
            
            invCnt += merge(s, mid, e, nums);
        }
        return invCnt;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(0, nums.size()-1, nums);
    }
};
