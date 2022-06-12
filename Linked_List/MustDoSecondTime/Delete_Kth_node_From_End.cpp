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

void deleteK(LinkedListNode<int>* head, int &k){
    if(head == NULL) return;
    deleteK(head->next,k);
    k--;
    if(k == -1 and head->next){
        head->next = head->next->next;
    }
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head == NULL)
        return head;
    deleteK(head, K);
    if(K > -1)
        return head->next;
    return head;
}