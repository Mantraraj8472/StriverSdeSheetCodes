// problem link:
// https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
//     unordered_map<int, int> hsh;
//     for(int i = 0; i < n; i++) hsh[arr[i]]++;
//     set<pair<int, int>> st;
//     for(auto i : hsh) st.insert({i.second, i.first});
//     vector<int> ans;
//     while(k--){
//         ans.push_back((*(--st.end())).second);
//         st.erase(--st.end());
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
    
    // By bucket sort
    unordered_map<int, int> hsh;
    for(int i = 0; i < n; i++) hsh[arr[i]]++;
    vector<int> bucket[n + 1];
    for(auto i : hsh) bucket[i.second].push_back(i.first);
    vector<int> ans;
    for(int i = n; i >= 1 and k; i--){
        if(bucket[i].size() != 0){
            for(int ele = 0; ele < bucket[i].size() and k; ele++) {
                k--;
                ans.push_back(bucket[i][ele]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
