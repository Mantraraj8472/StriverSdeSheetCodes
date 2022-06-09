#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    // Sometimes giving TLE maybe due to duplicacy
//     int ans = 1;
//     unordered_map<int, int> hsh;
//     for(int i = 0; i < n; i++)
//         hsh[arr[i]]++;
//     for(int i = 0; i < n; i++){
//         if(hsh.find(arr[i] - 1) == hsh.end()){
//             int curLen = 0, var = arr[i];
//             while(hsh.find(var) != hsh.end()){
//                 var++;
//                 curLen++;
//             }
//             ans = max(ans, curLen);
//         }
//     }
//     return ans;
    
    // Using unorderedSet
    unordered_set<int> st;
    int ans = 0;
    for(int i = 0; i < n; i++)
        st.insert(arr[i]);
    for(int i = 0; i < n; i++){
        if(st.find(arr[i] - 1) == st.end()){
            int curLen = 0, var = arr[i];
            while(st.find(var) != st.end()){
                var++;
                curLen++;
            }
            ans = max(ans, curLen);
        }
    }
    return ans;
}