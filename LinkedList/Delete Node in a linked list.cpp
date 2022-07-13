#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    while(node != NULL and node->next != NULL){
        node->data = node->next->data;
        if(node->next->next == NULL){
            node->next = NULL;
            break;
        }
        node = node->next;
    }
}