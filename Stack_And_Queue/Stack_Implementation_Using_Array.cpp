// problem link:
// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?topList=striver-sde-sheet-problems&leftPanelTab=0

// Stack class.
class Stack {
   
private:
    vector<int> st;
    int ind;
public:
    
    // We can also without maintaing ind by checking size of st
    Stack(int capacity) {
        ind = -1;
        st.resize(capacity, -1);
    }

    void push(int num) {
        ind++;
        if(ind < st.size())
            st[ind] = num;
    }

    int pop() {
        if(ind == -1)
            return -1;
        return st[ind--];
    }
    
    int top() {
        if(ind == -1)
            return -1;
        return st[ind];
    }
    
    int isEmpty() {
        return ind == -1;
    }
    
    int isFull() {
        return ind == st.size() - 1;
    }
    
};