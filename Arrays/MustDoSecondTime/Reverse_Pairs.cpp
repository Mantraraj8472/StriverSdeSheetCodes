#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int reversePairs(vector<int> &arr, int n){
	tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> st;
    st.insert({arr[0], 0});
    int ans = 0;
    for(int i = 1; i < n; i++){
        int smaller = st.order_of_key({(2 * arr[i]), i});
        ans += (st.size() - smaller);
        st.insert({arr[i], i});
    }
    return ans;
}