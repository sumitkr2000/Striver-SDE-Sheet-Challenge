class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) {
            return NULL;
        }
        
        Node* temp = root;
        
        while(temp != NULL) {
            Node* curr = temp;
            
            while(curr != NULL && curr -> left != NULL) {
                curr -> left -> next = curr -> right;
                
                if(curr -> next != NULL) {
                    curr -> right -> next = curr -> next -> left;
                }
                curr = curr -> next;
            }
            temp = temp -> left;
        }
        return root;
    }
};
