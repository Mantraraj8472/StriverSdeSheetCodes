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

Node *reverse(Node* head){
    if(head == NULL or head->next == NULL) return head;
    Node *newReverse = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newReverse;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head == NULL) return head;
    Node *prevTail = NULL, *curHead = head, *ans = head;
	for(int i = 0; i < n and curHead; i++){
        Node *temp = curHead;
        if(b[i] == 0) continue; 
        b[i]--;
        while(temp->next and b[i] > 0) {
            temp = temp->next;
            b[i]--;
        }
        Node *nextHead = temp->next; 
        temp->next = NULL;
        Node *curRev = reverse(curHead);
        if(i == 0) ans = curRev; 
        if(prevTail) prevTail->next = curRev; 
        while(curRev->next) curRev = curRev->next;
        prevTail = curRev;
        curHead = nextHead;
    }
    if(prevTail)
        prevTail->next = curHead;
    return ans;
}