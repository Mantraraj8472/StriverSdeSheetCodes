// problem link:
// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&leftPanelTab=0

void insert(stack<int> &st, int ele){
    if(st.empty() or st.top() <= ele){
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, ele);
    st.push(top);
}

void sort(stack<int> &st){
    if(st.size() <= 1) return;
    int top = st.top();
    st.pop();
    sort(st);
    insert(st, top);
}

void sortStack(stack<int> &stack)
{
	sort(stack);
}