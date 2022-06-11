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

Node* getMid(Node *head){
    if(head == NULL or head->next == NULL) return head;
    Node *slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    return getMid(head);
}