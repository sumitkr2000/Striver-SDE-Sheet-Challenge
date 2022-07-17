int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int> pq;
        
    for(int i = 0; i < size; i++) {
        pq.push(arr[i]);
    }

    while(K > 1) {
        pq.pop();
        K--;
    }

    int ans = pq.top();
    return ans;
}
