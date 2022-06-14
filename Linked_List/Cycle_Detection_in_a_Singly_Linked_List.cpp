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

bool detectCycle(Node *head)
{
	// Method 1: Using hashing
//     unordered_map<Node*, bool> hsh;
//     while(head){
//         if(hsh.find(head) != hsh.end()) return true;
//         hsh[head] = true;
//         head = head->next;
//     }
//     return false;
    
    // In constant space complexity
    Node *slow = head, *fast = head;
    if(fast->next == NULL) return false;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast and fast and fast->next);
    if(fast == NULL or fast->next == NULL) return false;
    return true;
}