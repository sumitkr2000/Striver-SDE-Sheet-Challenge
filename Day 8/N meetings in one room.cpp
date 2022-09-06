class Solution
{
    private:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> meeting(n);
        for(int i = 0; i < n; i++) {
            meeting[i] = {start[i], end[i]};
        }
        
        sort(meeting.begin(), meeting.end(), comp);
        
        int cnt = 1;
        int lastEnd = meeting[0][1];
        
        for(int i = 1; i < n; i++) {
            if(meeting[i][0] > lastEnd) {
                cnt++;
                lastEnd = meeting[i][1];
            }
        }
        return cnt;
    }
};
