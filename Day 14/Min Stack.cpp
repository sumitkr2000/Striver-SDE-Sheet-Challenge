class MinStack {
public:
    stack<long> st;
    long mini = INT_MAX;
    
    MinStack() {        
    }
    
    void push(int val) {
        long value = val;
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else {
            if(value < mini) {
                st.push(2 * value * 1LL - mini);
                mini = value;
            }
            else {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.top() < mini) {
            mini = 2 * mini * 1LL - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) {
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
