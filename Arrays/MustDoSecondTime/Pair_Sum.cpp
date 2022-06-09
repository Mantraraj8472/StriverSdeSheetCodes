#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while(l < r){
        int curSum = arr[l] + arr[r];
        if(curSum == s){
            int curR = r;
            while(l < curR and arr[curR] == arr[r]){
                ans.push_back({arr[l], arr[r]});
                curR--;
            }
            l++;
        }
        else if(curSum < s) l++;
        else r--;
    }
    return ans;
}