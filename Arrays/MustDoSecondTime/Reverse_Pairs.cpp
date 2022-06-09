#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int merge(vector<int> &arr, int l, int mid, int r){
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    vector<int> left(l_sz), right(r_sz);
    for(int i = l; i <= mid; i++){
        left[i - l] = arr[i];
    }
    for(int i = mid + 1; i <= r; i++){
        right[i - mid - 1] = arr[i];
    }
    
    // We have to check here because if we check parrallely with merging loop then it will not check for entire right array as r_i++ and that element will be skipped
    int mergePairs = 0;
    for(int rt : right){
        int l_i = upper_bound(left.begin(), left.end(), 2 * rt) - left.begin();
        mergePairs += left.size() - l_i;
    }
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int l_i = 0, r_i = 0;
    for(int i = l; i <= r; i++){
        if(left[l_i] > right[r_i]){
            arr[i] = right[r_i++];
        }
        else arr[i] = left[l_i++];
    }
    return mergePairs;
}

int mergeSort(vector<int> &arr, int l, int r){
    if(l == r) return 0;
    int mid = (l + r) >> 1;
    int left = mergeSort(arr, l, mid);
    int right = mergeSort(arr, mid + 1, r);
    int mergePairs = merge(arr, l, mid, r);
    return left + right + mergePairs;
}

int reversePairs(vector<int> &arr, int n){
    
    // I have made container of pair to handle cases of duplicacy
// 	tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> st;
//     st.insert({arr[0], 0});
//     int ans = 0;
//     for(int i = 1; i < n; i++){
//         int smaller = st.order_of_key({(2 * arr[i]), i});
//         ans += (st.size() - smaller);
//         st.insert({arr[i], i});
//     }
//     return ans;
    
    // Using MergeSort method
    return mergeSort(arr, 0, n - 1);
}