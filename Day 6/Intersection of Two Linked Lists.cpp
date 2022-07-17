#include <bits/stdc++.h> 
int findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL || secondHead == NULL) {
        return NULL;
    }
    
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while(temp1 != temp2) {
        if(temp1 == NULL) {
            temp1 = secondHead;
        }
        else{
            temp1 = temp1 -> next;
        }

        if(temp2 == NULL) {
            temp2 = firstHead;
        }
        else{
            temp2 = temp2 -> next;
        }
    }
    if(temp1 == NULL) {
        return -1;
    }
    else{
        return temp1->data;
    }
}
