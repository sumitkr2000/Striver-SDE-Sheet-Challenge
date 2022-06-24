class Solution {
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int value) {
        
        ListNode* temp = new ListNode(value);
        
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
    
    ListNode* add(ListNode* first, ListNode* second) {
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
            
        int carry = 0;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL) {
                val1 = first -> val;
            }
            
            int val2 = 0;
            if(second != NULL) {
                val2 = second -> val;
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
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = add(l1, l2);
        
        return ans;
        
    }
};
