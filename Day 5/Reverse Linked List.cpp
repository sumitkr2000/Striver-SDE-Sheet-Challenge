class Solution {
private:
    //Approach 2: Recursive
    ListNode* reverse(ListNode* head) {
        //base case
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode* newHead = reverse(head -> next);
        
        ListNode* curr = head -> next;
        curr -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        
        //Approach 1: Iterative
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        head = prev;
        return prev;
        
        /*//Approach 2: Recursive
        return reverse(head);
        */
    }
};
