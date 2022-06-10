#include<unordered_map>
void insertAtTail(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, int d) {

      LinkedListNode<int>* temp = new LinkedListNode<int>(d);

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

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
      LinkedListNode<int>* cloneHead = NULL;
      LinkedListNode<int>* cloneTail = NULL;

      LinkedListNode<int>* temp = head;

      //step 1: creating a clone list
      while(temp != NULL) {
          insertAtTail(cloneHead, cloneTail, temp -> data);
          temp = temp -> next;
      }

      //step 2: mapping original list data to clone list
      unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> originalToclone;

      LinkedListNode<int>* originalNode = head;
      LinkedListNode<int>* cloneNode = cloneHead;

      while(originalNode != NULL) {
           originalToclone[originalNode] = cloneNode;
           originalNode = originalNode -> next;
           cloneNode = cloneNode -> next;
      }

      //step 3: cloning the random pointers
      originalNode = head;
      cloneNode = cloneHead;

      while(originalNode != NULL) {
          cloneNode -> random = originalToclone[originalNode -> random];
          originalNode = originalNode -> next;
          cloneNode = cloneNode -> next;
      }
      return cloneHead;
}
