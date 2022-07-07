// problem link:
// https://www.codingninjas.com/codestudio/problems/next-greater-element_799354?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.size() and arr[i] > arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}