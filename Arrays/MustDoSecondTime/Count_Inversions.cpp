#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

long long getInversions(long long *arr, int n){

    // Here I have used pair container to handle duplicacy cases.
    // Although it is given in question that there are no duplicates but it has :((
    tree<pair<long long, long long>,  null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;
    st.insert({arr[0], 0});
    long long ans = 0ll;
    for(int i = 1; i < n; i++){
        long long smaller = 0ll + st.order_of_key({arr[i], i});
        long long sz = st.size();
        ans += (sz - smaller);
        st.insert({arr[i], i});
    }
    return ans;
}