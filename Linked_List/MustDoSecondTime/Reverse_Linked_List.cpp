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
    if(head == NULL or head->next == NULL) return head;
//     return reverse(head);
    
    // Iterative approach
//     LinkedListNode<int> *cur = head->next, *prev = head;
//     prev->next = NULL;
//     while(cur){
//         LinkedListNode<int> *curNext = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = curNext;
//     }
//     return prev;
    
    // Iterative approach using stack
    stack<LinkedListNode<int> *> st;
    while(head){
        st.push(head);
        head = head->next;
    }
    LinkedListNode<int> *ans = st.top(), *temp = st.top();
    st.pop();
    while(st.size()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return ans;
}