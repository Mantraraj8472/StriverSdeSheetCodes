// problem link:
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?topList=striver-sde-sheet-problems&leftPanelTab=0

struct node{
    int data;
    node *next;
    
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue {

private:
    node *head = NULL, *tail = NULL;
public:
    // Let's implement it using Linked List
    Queue() {
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int data) {
        node *insert = new node(data);
        if(tail == NULL){
            tail = head = insert;
            return;
        }
        tail->next = insert;
        tail = insert;
    }

    int dequeue() {
        if(head == NULL)
            return -1;
        int ans = head->data;
        node *temp = head;
        if(head == tail) 
            tail = NULL;
        head = head->next;
        delete(temp);
        return ans;
    }

    int front() {
        return head ? head->data : -1;
    }
};