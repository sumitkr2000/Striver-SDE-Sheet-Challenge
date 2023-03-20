class Solution {
public:
	Node* mergeList(Node* l1, Node* l2) {

	    Node* dummy = new Node(-1);
	    Node* temp = dummy;

	    while(l1 && l2) {
		if(l1 -> data < l2 -> data) {
		    temp -> bottom = l1;
		    temp = l1;
		    l1 = l1 -> bottom;
		}
		else {
		    temp -> bottom = l2;
		    temp = l2;
		    l2 = l2 -> bottom;
		}
	    }

	    if(l1 != NULL) {
		temp -> bottom = l1;
	    }
	    else {
		temp -> bottom = l2;
	    }

	    return dummy -> bottom;
	}
	
public:
	Node *flatten(Node *root) {
		
	   if(root == NULL || root -> next == NULL) {
		return root;
	    }

	    root -> next = flatten(root -> next);

	    root = mergeList(root, root -> next);

	    return root;
	}
};
