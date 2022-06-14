#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node *getMid(Node *head){
    if(head == NULL or head->next == NULL) return head;
    Node *slow = head, *fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node *h1, Node *h2){
    Node *cur = NULL, *ans = NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    while(h1 and h2){
        if(h1->data < h2->data){
            if(ans == NULL){
                ans = h1;
                cur = h1;
            }
            else{
                cur->child = h1;
                cur = cur->child;
            }
            h1 = h1->child;
        }
        else{
            if(ans == NULL){
                ans = h2;
                cur = h2;
            }
            else{
                cur->child = h2;
                cur = cur->child;
            }
            h2 = h2->child;
        }
    }
    if(h1) cur->child = h1;
    if(h2) cur->child = h2;
    return ans;
}

Node* mergeSort(Node *head){
    if(head == NULL or head->next == NULL) return head;
    Node *mid = getMid(head);
    Node *midNext = mid->next;
    mid->next = NULL;
    mergeSort(head);
    mergeSort(midNext);
    return merge(head, midNext);
}

Node* flattenLinkedList(Node* head) 
{
    return mergeSort(head);
}
