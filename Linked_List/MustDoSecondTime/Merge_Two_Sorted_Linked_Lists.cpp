#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

// Problem link:
// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?topList=striver-sde-sheet-problems&leftPanelTab=0

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* fp = first, *sp = second, *temp = NULL, *ans = NULL;
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    while(fp and sp){
        if(fp->data < sp->data){
            if(temp == NULL){
                temp = fp;
                ans = fp;
            }
            else{
                temp->next = fp;
                temp = temp->next;
            }
            fp = fp->next;
        }
        else{
            if(temp == NULL){
                temp = sp;
                ans = sp;
            }
            else{
                temp->next = sp;
                temp = temp->next;
            }
            sp = sp->next;
        }
    }
    // If we have not checked initially that either or two list is empty or not, here we have to check about temp that either temp is NULL or not.
    if(fp) temp->next = fp;
    if(sp) temp->next = sp;
    return ans;
}
