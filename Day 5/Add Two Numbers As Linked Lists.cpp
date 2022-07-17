#include <bits/stdc++.h> 
void insertAtTail(Node* &head, Node* &tail, int value) {
        
        Node* temp = new Node(value);
        
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
Node* add(Node* first, Node* second) {

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;

    while(first != NULL || second != NULL || carry != 0) {

        int val1 = 0;
        if(first != NULL) {
            val1 = first -> data;
        }

        int val2 = 0;
        if(second != NULL) {
            val2 = second -> data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if(first != NULL) {
            first = first -> next;
        }
        if(second != NULL) {
            second = second -> next;
        }
    }
    return ansHead;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* ans = add(head1, head2);       
    return ans;
}
