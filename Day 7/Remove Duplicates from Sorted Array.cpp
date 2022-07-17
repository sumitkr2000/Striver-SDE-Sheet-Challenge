int removeDuplicates(vector<int> &arr, int n) {
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		if(arr[i] != arr[i+1]) {
			cnt++;
		}
	}
	if(cnt == 0) {
		cnt = 1;
	}
	return cnt;
}
