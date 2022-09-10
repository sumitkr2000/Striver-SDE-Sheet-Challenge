class MyStack {
public:
    queue<int> q;
    
    MyStack() {       
    }
    
    void push(int x) { 
        q.push(x);
        for(int i = 0 ; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() { 
        return q.size() == 0;
    }
};
