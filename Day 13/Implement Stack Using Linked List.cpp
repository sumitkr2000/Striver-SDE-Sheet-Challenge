void MyStack ::push(int x) 
{
    StackNode* newNode = new StackNode(x);
    newNode -> next = top;
    top = newNode;
}

int MyStack ::pop() 
{
    if(top == NULL) {
        return -1;
    }
    
    StackNode* temp = top;
    int topData = top -> data;
    top = top -> next;
    temp -> next = NULL;
    return topData;
}
