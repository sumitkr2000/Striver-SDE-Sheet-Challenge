class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i = 1, j = 0;
    	int ans = 1, cnt = 1;
    	
    	while(i < n && j < n) {
    	    if(arr[i] <= dep[j]) {
    	        cnt++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]) {
    	        cnt--;
    	        j++;
    	    }
    	    
    	    ans = max(ans, cnt);
    	}
    	return ans;
    }
};
