class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;
    
    int getSize() {
        if(maxHeap.size() == minHeap.size()) {
            return 0;
        }
        else if(maxHeap.size() > minHeap.size()) {
            return 1;
        }
        return -1;
    }
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        switch(getSize()) {
            case 0:
                if(num > median) {
                    minHeap.push(num);
                    median = minHeap.top();
                }
                else {
                    maxHeap.push(num);
                    median = maxHeap.top();
                }
                break;
                
            case 1:
                if(num > median) {
                    minHeap.push(num);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                break;
                
            case -1:
                if(num < median) {
                    maxHeap.push(num);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                break;
        }
    }
    
    double findMedian() {
        return median;
    }
};
