class StackNode {
public:
    int data;
    StackNode* next;
    
    StackNode(int x) {
        data = x;
        next = NULL;
    }
}

class Solution {
public:
    StackNode top = NULL;
    
    void push(int x)  {

        StackNode* newNode = new StackNode(x);
        newNode -> next = top;
        top = newNode;
    }

    int pop() {

        if(top == NULL) {
            return -1;
        }

        StackNode* temp = top;
        int topData = top -> data;
        top = top -> next;
        temp -> next = NULL;
        return topData;
    }
};
