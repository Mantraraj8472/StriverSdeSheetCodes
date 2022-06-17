#include <bits/stdc++.h> 
#define ll long 
long getTrappedWater(long *arr, int n){
//     vector<ll> leftMax(n, 0), rightMax(n, 0);
//     leftMax[0] = arr[0];
//     for(int i = 1; i < n; i++){
//         leftMax[i] = max(arr[i], leftMax[i - 1]);
//     }
//     rightMax[n - 1] = arr[n - 1];
//     for(int i = n - 2; i >= 0; i--){
//         rightMax[i] = max(arr[i], rightMax[i + 1]);
//     }
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += min(leftMax[i], rightMax[i]) - arr[i];
//     }
//     return ans;
    
    // In constant space complexity
    // What's the intuition?
    // We have to add for each pillar min(leftMax, rightMax) - arr[i]
    // Now arr[l] <= arr[r] will make us sure that there exists a pillar of height which is greater than current pillar. So we can say that there exists a pillar of height greater than or equal to leftMax to the right as for any leftMax our condition arr[leftMax] <= arr[r]. So by this we are sure that leftMax is minimum of leftMax and rightMax. Similarly for right part
    ll l = 0, r = n - 1, leftMax = 0, rightMax = 0, ans = 0;
    while(l < r){
        if(arr[l] <= arr[r]){
            leftMax = max(arr[l], leftMax);
            ans += leftMax - arr[l++];
        }
        else{
            rightMax = max(arr[r], rightMax);
            ans += rightMax - arr[r--];
        }
    }
    return ans;
}