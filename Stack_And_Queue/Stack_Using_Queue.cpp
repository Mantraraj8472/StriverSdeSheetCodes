// problem link:
// https://www.codingninjas.com/codestudio/problems/stack-using-queue_795152?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

class Stack {
    private:
    
    // If we use single queue then at the time of appending we will first get the size of the queue and then append data to the queue. Now we will run loop of size 'queue_size' and push front element to queue and pop front element so now pushed element is at the front of the queue and order
	queue<int> q1, q2;

   public:
    Stack() {
        queue<int> empty;
        q1 = empty;
        q2 = empty;        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.size() == 0;
    }

    void push(int element) {
        if(q1.size() == 0){
            q1.push(element);
            return;
        }
        while(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(element);
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if(q1.size() == 0)
            return -1;
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        return q1.size() ? q1.front() : -1;
    }
};