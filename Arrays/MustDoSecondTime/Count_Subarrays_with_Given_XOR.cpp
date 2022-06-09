#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> hsh;
    // This is used when curXor becomes x
    hsh[0] = 1;
    int curXor = 0, ans = 0, n = arr.size();
    for(int i = 0; i < n; i++){
        curXor ^= arr[i];
        if(hsh.find(curXor ^ x) != hsh.end()) 
            ans += hsh[curXor ^ x];
        hsh[curXor]++;
    }
    return ans;
}