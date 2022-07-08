// problem link:
// https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

int largestRectangle(vector < int > & heights) {
    int n = heights.size();
    vector<int> nxtS(n, n), prvS(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.size() and heights[i] < heights[st.top()]){
            nxtS[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    st = stack<int>();
    for(int i = n - 1; i >= 0; i--){
        while(st.size() and heights[i] < heights[st.top()]){
            prvS[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, heights[i] * (nxtS[i] - prvS[i] -1));
    }
    return ans;
}