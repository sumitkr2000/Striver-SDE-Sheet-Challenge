class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode *fast = head, *slow = head;
        
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
