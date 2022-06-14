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

void isPalin(LinkedListNode<int>* head1, LinkedListNode<int>* &head2, bool &ans){
    if(head1 == NULL) return;
    isPalin(head1->next, head2, ans);
    if(head1->data != head2->data) ans = false;
    head2 = head2->next;
}

LinkedListNode<int> *getMid(LinkedListNode<int> *head){
    LinkedListNode<int> *slow = head, *fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    if(head == NULL or head->next == NULL) return head;
    LinkedListNode<int> *ans = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;
}

bool isPalindrome(LinkedListNode<int> *head) {
//     bool ans = true;
//     LinkedListNode<int> *temp = head;
//     isPalin(head, temp, ans);
//     return ans;
    
    // In constant space complexity
    if(head == NULL) return true;
    LinkedListNode<int> *mid = getMid(head);
    LinkedListNode<int> *midNext = reverse(mid->next);
    mid->next = midNext;
    mid = mid->next;
    while(mid){
        if(head->data != mid->data) return false;
        mid = mid->next;
        head = head->next;
    }
    return true;
}