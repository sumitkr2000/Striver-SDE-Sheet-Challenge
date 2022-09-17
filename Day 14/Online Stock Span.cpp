class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i = -1;
    
    StockSpanner() {
    }
    
    int next(int price) {
        
        i++;
        
        while(!st.empty() && st.top().second <= price) {
            st.pop();
        }
        
        if(st.empty()) {
            st.push({i, price});
            return i+1;
        }
        
        int ans = i - st.top().first;
        st.push({i, price});
        return ans;
    }
};
