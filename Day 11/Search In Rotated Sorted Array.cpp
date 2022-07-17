int getpivot(int* arr, int n) {
    
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    
    while(start<end) {
        
        if(arr[0]<=arr[mid]) {
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}
int binarysearch(int* arr, int s, int e, int k) {
    
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    
    while(start <= end) {
        
        if(k == arr[mid]) {
            return mid;
        }
        else if(k > arr[mid]) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int search(int* arr, int n, int key) {
	
    int pivot = getpivot(arr,n);
    if(key >= arr[pivot] && key <= arr[n-1]) {
        return binarysearch(arr, pivot, n-1, key);
    }
    else{
        return binarysearch(arr, 0, pivot, key);
    }
}
