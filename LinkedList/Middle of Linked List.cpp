#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/


// Use slow and fast pointer approach

Node *findMiddle(Node *head) {
    Node* slow = head, *fast = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
        
        if(fast != NULL)
            fast = fast->next;
    }
    return slow;
}