class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode *fast = temp, *slow = temp;
        
        while(n > 0) {
            fast = fast -> next;
            n--;
        }
        
        if(fast -> next == NULL) {
            return head -> next;
        }
        
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};
