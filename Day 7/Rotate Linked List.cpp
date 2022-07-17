#include <bits/stdc++.h> 
Node *rotate(Node *head, int k) {
     
    if(head == NULL || head -> next == NULL) return head;
        
    vector<int> v;
    Node* temp = head;

    while(temp != NULL) {
        v.push_back(temp->data);
        temp = temp -> next;
    }

    int n = v.size();
    vector<int> copy(n);

    for(int i = 0; i < n; i++) {
        copy[(i + k) % n] = v[i];
    }

    int i = 0;
    temp = head;
    while(temp != NULL) {
        temp -> data = copy[i];
        temp = temp -> next;
        i++;
    }
    return head;
}
