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

// Problem link:
// https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end-in-linked-list_799912?topList=striver-sde-sheet-problems&leftPanelTab=1

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
//     if(head == NULL)
//         return head;
//     deleteK(head, K);
//     if(K > -1)
//         return head->next;
//     return head;
    
    // Iterative and time complexity of O(N) and space complexity of O(1)
    LinkedListNode<int> *start = new LinkedListNode<int>(1e9);
    start->next = head;
    LinkedListNode<int> *first = start, *second = start;
    for(int i = 1; i <= K; i++)
        second = second->next;
    while(second->next){
        first = first->next;
        second = second->next;
    }
    if(first->next)
        first->next = first->next->next;
    return start->next;
}