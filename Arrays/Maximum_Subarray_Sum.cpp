#include<bits/stdc++.h>
#define ll long long

ll maxSubarraySum(int arr[], int n)
{
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
    }
    return ans;
//     vector<long long> pre(n+1,0);
//     pre[0]=0;
// 	for(int i=1;i<=n;i++){
//     	pre[i]=pre[i-1]+arr[i-1];
//     }
//     vector<long long> mini = pre;
//     for(int i=1;i<=n;i++){
//         mini[i]=min(pre[i],mini[i-1]);
//     }
//     long long ans=pre[0];
//     for(int i=n;i>0;i--){
//         long long var=pre[i]-mini[i];
//         ans=max(ans,var);
//         ans=max(ans,pre[i]);
//     }
    return ans;
}