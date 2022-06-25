class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* forward = NULL;
	int cnt = 0;
	
	while(curr != NULL && cnt < k) {
		
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
		cnt++;
	}
        
    int len = 0;
    while(forward != NULL) {
         forward = forward -> next;
         len++;
    }
	
	if(forward != NULL && len >= k) {
		head -> next = reverseKGroup(forward, k);
	}
    else if(forward != NULL && len < k){
        head -> next = forward;
    }
	
	return prev;
    }
};
