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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //Initialize the variables
    LinkedListNode<int> *prev_node = head, *curr_node, *next_node;
    
    if(head != NULL)
        curr_node = head->next;
    
    if(curr_node != NULL)
        next_node = curr_node->next;
    
    while(curr_node != NULL){
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
        if(next_node != NULL)
            next_node = next_node->next;
    }
    if(head != NULL)
        head->next = NULL;
    
    return prev_node;
}

// e.g:

// 1 2 3 4 5 -1

// ^ ^ ^
// | | |
// | | next_node
// | |
// | curr_node
// |
// prev_node