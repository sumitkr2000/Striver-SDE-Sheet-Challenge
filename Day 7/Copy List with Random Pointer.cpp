class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) {
            return NULL;
        } 
        
        Node* temp = head;
        
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = temp -> next -> next;
        }
        
        temp = head;
        
        while(temp != NULL) {
            if(temp -> random == NULL) {
                temp -> next -> random = NULL;
            }
            else {
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        
        temp = head;
        Node* dummy = new Node(-1);
        dummy -> next = temp -> next;
        Node* forward = temp -> next -> next;
        
        while(forward != NULL) {
            temp -> next ->next = forward -> next;
            temp -> next = forward;
            temp = forward;
            forward = forward -> next -> next;
        }
        temp -> next = NULL;
        
        return dummy -> next;
    }
};
