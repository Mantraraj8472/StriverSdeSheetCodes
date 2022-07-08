// problem link:
// https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ns(n, n), ps(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.size() and a[i] < a[st.top()]){
            ns[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    st = stack<int>();
    for(int i = n - 1; i >= 0; i--){
        while(st.size() and a[i] < a[st.top()]){
            ps[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    vector<int> ans(n, INT_MIN);
    for(int i = 0; i < n; i++){
        int len = ns[i] - ps[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }
    // As some are left for calculation and for particular length L we can say that ans[L] >= max(ans[L + 1], ans[L + 2], ...)
    for(int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return ans;
}