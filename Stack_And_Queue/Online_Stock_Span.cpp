// problem link:
// https://www.codingninjas.com/codestudio/problems/span-of-ninja-coin_1475049?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
    stack<int> st;
    int n = price.size();
    vector<int> ans(n, -1);
    
    for(int i = n - 1; i >= 0; i--){
        while(st.size() and price[i] > price[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == -1)
            ans[i] = i + 1;
        else
            ans[i] = i - ans[i];
    }
    return ans;
}