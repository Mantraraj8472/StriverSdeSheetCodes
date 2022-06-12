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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry = 0;
    Node* head = new Node(0);
    Node* ans = head;
    while(head1 and head2){
        int sum = head1->data + head2->data + carry;
        Node* node = new Node(sum % 10);
        carry = sum / 10;
        head->next = node;
        head = head->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head2) 
        swap(head1, head2);
    while(head1){
        int sum = head1->data + carry;
        Node* node = new Node(sum % 10);
        carry = sum / 10;
        head->next = node;
        head = head->next;
        head1 = head1->next;
    }
    if(carry){
        Node* node = new Node(carry);
        head->next = node;
    }
    return ans->next;
}