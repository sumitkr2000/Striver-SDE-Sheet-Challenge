Node* floydDetectCycle(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
   
    while(slow != NULL && fast != NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast) {
        return slow;
        }
    }
    
    return NULL;
}

Node *firstNode(Node *head)
{
    if(head == NULL) 
    return NULL;

    Node* temp = floydDetectCycle(head);
	if(temp == NULL) {
		return NULL;
	}
    Node* slow = head;

    while(slow != temp) {
        slow = slow -> next;
        temp = temp -> next;
    }

    return slow;
}
