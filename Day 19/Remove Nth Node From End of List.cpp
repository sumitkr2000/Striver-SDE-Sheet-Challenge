class Solution {
private:
    int getLength(ListNode* head) {
        
        ListNode* temp = head;
        int len = 0;
        
        while(temp != NULL) {
            temp = temp -> next;
            len++;
        }
        return len;
    }
        
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head -> next == NULL) {
            return NULL;
        }
        
        int length = getLength(head);
        
        int reqlength = length - n + 1;
        
        ListNode* temp = head;
        int count = 1;
        
        if(reqlength == 1) {
            
            ListNode* curr = head -> next;
            temp -> next = temp -> next -> next;
            head = curr;
            return head;
        }
        
        while(count < reqlength - 1) {
            temp = temp -> next;
            count++;
        }
        temp -> next = temp -> next -> next;
        
        return head;
    }
};
