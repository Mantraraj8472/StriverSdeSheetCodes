#include <bits/stdc++.h> 
/********************************

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

********************************/

// Problem link:
// https://www.codingninjas.com/codestudio/problems/rotate-linked-list_920454?topList=striver-sde-sheet-problems&leftPanelTab=0

Node *rotate(Node *head, int k) {
    if(head == NULL or head->next == NULL or k == 0) return head;
    int len = 0;
    Node *temp = head, *tail = head;
    while(temp){
        len++;
        tail = temp;
        temp = temp->next;
    }
    k %= len;
    k = len - k;
    temp = head;
    k--;
    while(k > 0){
        k--;
        temp = temp->next;
    }
    tail->next = head;
    Node *ans = temp->next;
    temp->next = NULL;
    return ans;
}