#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> hsh;
    LinkedListNode<int> *temp = head, *tempans = NULL, *ans = NULL;
    hsh[NULL] = NULL;
    while(temp){
        LinkedListNode<int> *node = new LinkedListNode<int>(temp->data);
        hsh[temp] = node;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(ans == NULL) {
            ans = hsh[temp];
            tempans = hsh[temp];
        }
        tempans->next = hsh[temp->next];
        tempans->random = hsh[temp->random];
        tempans = tempans->next;
        temp = temp->next;
    }
    return ans;
}
