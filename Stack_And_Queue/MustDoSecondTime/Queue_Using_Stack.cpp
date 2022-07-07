// problem link:
// https://www.codingninjas.com/codestudio/problems/queue-using-stack_799482?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

// class Queue {
//     private:
//     stack<int> s1, s2;
    
//     public:
//     Queue() {
//         s1 = stack<int>();
//         s2 = stack<int>();
//     }

//     void enQueue(int val) {
//         while(s1.size()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(val);
//         while(s2.size()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int deQueue() {
//         if(s1.size() == 0)
//             return -1;
//         int ans = s1.top();
//         s1.pop();
//         return ans;
//     }

//     int peek() {
//         return s1.size() ? s1.top() : -1;
//     }

//     bool isEmpty() {
//         return s1.size() == 0;
//     }
// };

// Amortised time complexity of O(1)
// As for all queries O(N) will be there

class Queue {
    private:
    stack<int> s1, s2;
    
    public:
    Queue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        if(s1.size() == 0 and s2.size() == 0)
            return -1;
        if(s2.size()){
            int ans = s2.top();
            s2.pop();
            return ans;
        }
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }

    int peek() {
        if(s1.size() == 0 and s2.size() == 0)
            return -1;
        if(s2.size())
            return s2.top();
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.size() == 0 and s2.size() == 0;
    }
};