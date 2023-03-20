class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
            
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry != 0) {  
            int sum = carry;
            
            if(l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            
            if(l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            
            int digit = sum%10;
            carry = sum/10;
            
            tail -> next = new ListNode(digit);
            tail = tail -> next;
        }

        return head -> next;
    }
};
