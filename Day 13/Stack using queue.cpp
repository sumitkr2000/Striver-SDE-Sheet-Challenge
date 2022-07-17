#include<queue>
class Stack {
	queue<int> q;
    queue<int> p;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        q.push(element);        
    }

    int pop() {
        
        if(q.empty()) {
            return -1;
        }
        else{
           while(q.size() != 1) {  
                p.push(q.front());
                q.pop();
            }

            int y = q.front();
            q.pop();

            while(p.size() != 0){
                q.push(p.front()); 
                p.pop();
            }
            return y; 
        }   
    }
        

    int top() {
        
        if(q.empty()) {
            return -1;
        }
        else {
           while(q.size() != 1) {
               p.push(q.front());
               q.pop();
           }
            
           int y = q.front(); 
           p.push(q.front());
           q.pop();
           while(!p.empty()){
               q.push(p.front());
               p.pop();
           }
           return y; 
        }
    }
};
