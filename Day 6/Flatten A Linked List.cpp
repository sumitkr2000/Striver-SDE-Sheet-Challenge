Node* getMid(Node* head) {
	
	Node* slow = head;
	Node* fast = head -> child;
	
	while(fast != NULL && fast -> child != NULL) {
		slow = slow -> child;
		fast = fast -> child -> child;
	}
	return slow;
}

Node* mergeList(Node* &left, Node* &right) {
	
	if(left == NULL) {
		return right;
	}
	if(right == NULL) {
		return left;
	}
	
	Node* ans = new Node(-1);
	Node* temp = ans;
	
	while(left != NULL && right != NULL) {
		if(left -> data < right -> data) {
			temp -> child = left;
			temp = left;
			left = left -> child;
		}
		else{
			temp -> child = right;
			temp = right;
			right = right -> child;
	    }
    }
    while(left != NULL) {
        temp -> child = left;
        temp = left;
        left = left -> child;
    }
    while(right != NULL) {
        temp -> child = right;
        temp = right;
        right = right -> child;
    }
	ans = ans -> child;
	return ans;
}

Node* mergeSort(Node* &head) {
        
    //base case
    if(head == NULL || head -> child == NULL) {
	     return head;
    }

    Node* mid = getMid(head);

	Node* left = head;
	Node* right = mid -> child;
	mid -> child = NULL;
	
	//recursive call
	left = mergeSort(left);
	right = mergeSort(right);
	
	Node* res = mergeList(left, right);
	
	return res;
}

Node* flattenLinkedList(Node* head) 
{
	
	Node* prev = head;
	Node* temp = prev;
	Node* curr = prev -> next;
	
	while(curr != NULL) {
		
		while(temp -> child != NULL) {
			temp = temp -> child;
		}
		temp -> child = prev -> next;
		prev = curr;
		curr = curr -> next;
	}
	prev -> next = prev -> child;
	
	Node* ans = mergeSort(head);
	
	return ans;
}
