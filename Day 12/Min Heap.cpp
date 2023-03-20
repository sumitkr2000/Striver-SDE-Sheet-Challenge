class Solution {
private:
    void insMh(int val, vector<int> &arr, int &size) {
    
        size++;
        int i = size;
        arr[i] = val;

        while(i > 1) {
            if(arr[i/2] > arr[i]) {
                swap(arr[i], arr[i/2]);
                i /= 2;
            }
            else {
                return;
            }
        }
    }

    int remove(vector<int> &arr, int &size) {

        int mini = arr[1];
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i <= size) {
            int ind = i;
            int lc = 2*i;
            int rc = 2*i + 1;      

            if(lc <= size && arr[lc] < arr[ind]) {
                ind = lc;
            }
            if(rc <= size && arr[rc] < arr[ind]) {
                ind = rc;
            }
            if(i == ind) {
                break;
            }
            swap(arr[i], arr[ind]);
            i = ind;
        }
        return mini;
    }

public:
    vector<int> minHeap(int n, vector<vector<int>>& q) {

        vector<int> arr(100000), ans;
        int size = 0;

        for(auto it: q) {
            if(it[0] == 0) {
                insMh(it[1], arr, size);
            }
            else {
                ans.push_back(remove(arr, size));
            }
        }
        return ans;
    }
};
