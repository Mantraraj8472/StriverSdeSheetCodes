#include <bits/stdc++.h> 
#define ll long 
long getTrappedWater(long *arr, int n){
    vector<ll> leftMax(n, 0), rightMax(n, 0);
    leftMax[0] = arr[0];
    for(int i = 1; i < n; i++){
        leftMax[i] = max(arr[i], leftMax[i - 1]);
    }
    rightMax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(leftMax[i], rightMax[i]) - arr[i];
    }
    return ans;
}