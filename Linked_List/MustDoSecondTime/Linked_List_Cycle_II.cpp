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

Node *firstNode(Node *head)
{
// 	unordered_map<Node*, int> hsh;
//     while(head){
//         if(hsh.find(head) != hsh.end()) return head;
//         hsh[head] = 1;
//         head = head->next;
//     }
//     return NULL;
    
    // In constant space complexity
    if(head == NULL or head->next == NULL) return NULL;
    Node *slow = head, *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast and fast and fast->next);
    if(fast == NULL or fast->next == NULL) return NULL;
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}