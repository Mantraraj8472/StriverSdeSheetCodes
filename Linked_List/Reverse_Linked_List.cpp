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

LinkedListNode<int> * reverse(LinkedListNode<int> *head){
    if(head == NULL or head->next == NULL) return head;
    LinkedListNode<int> *curNext = head->next;
    LinkedListNode<int> *newReverse = reverse(head->next);
    curNext->next = head;
    head->next = NULL;
    return newReverse;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    return reverse(head);
}