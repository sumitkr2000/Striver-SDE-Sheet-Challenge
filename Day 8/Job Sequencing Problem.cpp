class Solution 
{
    private:
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }
    
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, comp);
        
        int maxDead = 0;
        for(int i = 0; i < n; i++) {
            maxDead = max(maxDead, arr[i].dead);
        }
        
        vector<int> jobSeq(maxDead+1, -1);
        int jobs = 0, maxProfit = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j > 0; j--) {
                if(jobSeq[j] == -1) {
                    jobSeq[j] = arr[i].id;
                    jobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobs, maxProfit};
    } 
};
