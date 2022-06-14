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

int findIntersection(Node *firstHead, Node *secondHead)
{
//     unordered_map<Node*, int> hsh;
//     while(firstHead){
//         hsh[firstHead] = 1;
//         firstHead = firstHead->next;
//     }
//     while(secondHead){
//         if(hsh.find(secondHead) != hsh.end()) return secondHead->data;
//         secondHead = secondHead->next;
//     }
//     return -1;
    
    // In space complexity of O(1)
//     int len1 = 0, len2 = 0;
//     Node *h1 = firstHead, *h2 = secondHead;
//     while(h1){
//         len1++;
//         h1 = h1->next;
//     }
//     while(h2){
//         len2++;
//         h2 = h2->next;
//     }
//     if(len1 > len2) {
//         swap(firstHead, secondHead);
//         swap(len1, len2);
//     }
//     int diff = len2 - len1;
//     cout << diff << endl;
//     while(diff){
//         diff--;
//         secondHead = secondHead->next;
//     }
    
//     while(firstHead and secondHead){
//         if(firstHead == secondHead) return firstHead->data;
//         firstHead = firstHead->next;
//         secondHead = secondHead->next;
//     }
//     return -1;
    
    // Same concept of difference in length but using different approach
    
    Node *h1 = firstHead, *h2 = secondHead;
    while(h1 != h2){
        h1 = h1 == NULL ? secondHead : h1->next;
        h2 = h2 == NULL ? firstHead : h2->next;
    }
    return h1 == NULL ? -1 : h1->data;
}