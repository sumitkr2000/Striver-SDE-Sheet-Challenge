Node<int>* solve(Node<int>* first, Node<int>* second) {
	
	if(first -> next == NULL) {
		first -> next = second;
		return first;
	}
	
	Node<int>* prev = first;
	Node<int>* curr1 = prev -> next;
	Node<int>* temp = second;
	Node<int>* curr2 = temp -> next;
	
	while(temp != NULL && curr1 != NULL) {
		if(temp -> data >= prev -> data && temp -> data <= curr1 -> data) {
			prev -> next = temp;
			curr2 = temp -> next;
			temp -> next = curr1;
			prev = temp;
			temp = curr2;
		}
		else{
			prev = curr1;
			curr1 = curr1 -> next;
			
			if(curr1 == NULL) {
				prev -> next = temp;
				return first;
			}
		}
	}
	return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
	if(first == NULL) {
		return second;
    }
	if(second == NULL) {
		return first;
	}
	
	if(first -> data <= second -> data) {
		return solve(first, second);
	}
	else{
		return solve(second, first);
	}
}
