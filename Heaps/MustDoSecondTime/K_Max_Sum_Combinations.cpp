// problem link:
// https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Brute force
//     multiset<int> st;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             st.insert(a[i] + b[j]);
//         }
//     }
//     vector<int> ans;
//     while(k--){
//         ans.push_back(*(--st.end()));
//         st.erase(--st.end());
//     }
//     return ans;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set<pair<int, pair<int, int>>> st;
    vector<int> ans;
    st.insert({a[n - 1] + b[n - 1], {n - 1, n - 1}});
    while(k--){
        auto cur = *(--st.end());
        st.erase(--st.end());
        ans.push_back(cur.first);
        st.insert({a[cur.second.first] + b[cur.second.second - 1], {cur.second.first, cur.second.second - 1}});
        st.insert({a[cur.second.first - 1] + b[cur.second.second], {cur.second.first - 1, cur.second.second}});
    }
    return ans;
}