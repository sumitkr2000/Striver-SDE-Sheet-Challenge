LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
	LinkedListNode<int>* prev = NULL;
	LinkedListNode<int>* curr = head;
	LinkedListNode<int>* forward = NULL;
	
	while(curr != NULL) {
		
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
	}
	
	head = prev;
	
	return prev;
}
