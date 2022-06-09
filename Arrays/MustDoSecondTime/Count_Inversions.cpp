#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

long long merge(long long *arr, long long l, long long mid, long long r){
    long long l_sz = mid - l + 1, r_sz = r - mid;
    vector<long long> left(l_sz), right(r_sz);
    for(int i = l; i <= mid; i++)
        left[i - l] = arr[i];
    for(int i = mid + 1; i <= r; i++)
        right[i - mid - 1] = arr[i];
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    long long l_i = 0, r_i = 0, mergePairs = 0ll;
    for(int i = l; i <= r; i++){
        if(left[l_i] > right[r_i]){
            arr[i] = right[r_i++];
            mergePairs += (left.size() - l_i - 1);
        }
        else arr[i] = left[l_i++];
    }
    return mergePairs;
}

long long mergeSort(long long *arr, long long l, long long r){
    if(l == r)
        return 0ll;
    long long mid = (l + r) >> 1ll;
    long long left = mergeSort(arr, l, mid);
    long long right = mergeSort(arr, mid + 1, r);
    long long mergePairs = merge(arr, l, mid, r);
    return mergePairs + left + right;
}

long long getInversions(long long *arr, int n){
    // Here I have used pair container to handle duplicacy cases.
    // Although it is given in question that there are no duplicates but it has :((
//     tree<pair<long long, long long>,  null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;
//     st.insert({arr[0], 0});
//     long long ans = 0ll;
//     for(int i = 1; i < n; i++){
//         long long smaller = 0ll + st.order_of_key({arr[i], i});
//         long long sz = st.size();
//         ans += (sz - smaller);
//         st.insert({arr[i], i});
//     }
//     return ans;
    
    // Using mergeSort method
    return mergeSort(arr, 0, n - 1);
}