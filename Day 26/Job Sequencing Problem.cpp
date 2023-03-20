class Solution {
private:
    bool static comp(Job a, Job b) {
        return a.profit > b.profit;
    }
    
public:
    vector<int> JobScheduling(Job arr[], int n) { 
        
        sort(arr, arr+n, comp);
        
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
        
        vector<int> jobSeq(maxi+1, -1);
        int job = 0, profit = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j > 0; j--) {
                if(jobSeq[j] == -1) {
                    jobSeq[j] = arr[i].id;
                    job++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {job, profit};
    } 
};
