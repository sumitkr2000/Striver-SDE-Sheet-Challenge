#include <bits/stdc++.h> 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
   LinkedListNode<int>* dummy = new LinkedListNode<int>(1);
   LinkedListNode<int>* fast = dummy;
   LinkedListNode<int>* slow = dummy;

   dummy -> next = head;

   if(head == NULL || K == 0) {
       return head;
   }

   for(int i = 1; i <= K; i++) {
       fast = fast -> next;
   }

   while(fast -> next != NULL) {
       fast = fast -> next;
       slow = slow -> next;
   }
   slow -> next = slow -> next -> next;
   return dummy -> next;
}
