// problem link:
// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        while(st.size() and arr[i] < arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}