#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Brute force approach
//     sort(arr.begin(), arr.end());
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 if(arr[i] + arr[j] + arr[k] == K){
//                     st.insert({arr[i], arr[j], arr[k]});
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans;
//     for(auto v : st) ans.push_back(v);
//     return ans;
    
    // Using hashmap
//     unordered_map<int, int> hsh;
//     sort(arr.begin(), arr.end());
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++)
//         hsh[arr[i]]++;
//     for(int i = 0; i < n; i++){
//         hsh[arr[i]]--;
//         for(int j = i + 1; j < n; j++){
//             hsh[arr[j]]--;
//             if(hsh[K - arr[i] - arr[j]] > 0)
//                 st.insert({arr[i], arr[j], K - arr[i] - arr[j]});
//         }
//         for(int j = i + 1; j < n; j++)
//             hsh[arr[j]]++;
//     }
//     vector<vector<int>> ans;
//     for(auto v : st) ans.push_back(v);
//     return ans;
    
    // Using two pointer approach
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i != 0 and arr[i] == arr[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while(l < r){
            if(arr[i] + arr[l] + arr[r] == K){
                ans.push_back({arr[i], arr[l], arr[r]});
                int li = l;
                while(l < r and arr[li] == arr[l]) l++;
                int ri = r;
                while(l < r and arr[ri] == arr[r]) r--;
            }
            else if(arr[i] + arr[l] + arr[r] < K)
                l++;
            else 
                r--;
        }
    }
    return ans;
}