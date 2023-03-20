class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        
        while(fast -> next && fast -> next -> next) {
            fast = fast-> next -> next;
            slow = slow -> next;
        }
        
        ListNode* temp = slow -> next;
        ListNode *prev = NULL, *fwd = NULL;
        
        while(temp) {
            fwd = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = fwd;
        }

        slow = head;
        while(prev) {
            if(slow -> val != prev -> val) {
                return false;
            }
            slow = slow -> next;
            prev = prev -> next;
        }
        return true;
    }
};
