class Queue {
    int *arr;
    int frontt;
    int rear;
public:
    Queue() {
        arr = new int[10000];
        frontt = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return frontt == rear;
    }

    void enqueue(int data) {
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if(frontt == rear) {
            return -1;
        }
        else{
            int temp = arr[frontt];
            arr[frontt] = -1;
            frontt++;
            if(frontt == rear) {
                frontt = 0;
                rear = 0;
            }
            return temp;
        }
    }

    int front() {
        if(frontt == rear) {
            return -1;
        }
        else{
            return arr[frontt];
        }
    }
};
