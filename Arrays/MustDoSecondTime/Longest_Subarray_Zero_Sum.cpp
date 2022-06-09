#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int, int> hsh;
    int curSum = 0, ans = 0, n = arr.size();
    // As for curSum = 0, the length will be equal to i + 1
    hsh[0] = -1;
    for(int i = 0; i < n; i++){
        curSum += arr[i];
        if(hsh.find(curSum) != hsh.end()){
            ans = max(ans, i - hsh[curSum]);
        }
        else hsh[curSum] = i;
    }
    return ans;
}