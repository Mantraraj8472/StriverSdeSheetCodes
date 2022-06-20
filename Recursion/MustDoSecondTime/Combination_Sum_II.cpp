// problem link:
// https://www.codingninjas.com/codestudio/problems/combination-sum-ii_1112622?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

void solve(int ind, int sum, int n, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int target){
    if(ind == n and sum == target){
        ans.push_back(temp);
        return;
    }
    if(ind == n or sum > target) return;
    int i = ind;
    int fre = 0;
    while(i < n and arr[i] == arr[ind]) i++, fre++;
    solve(i, sum, n, arr, temp, ans, target);
    for(int j = 1; j <= fre; j++) {
        temp.push_back(arr[ind]);
        solve(i, sum + j * arr[ind], n, arr, temp, ans, target);
    }
    for(int j = 1; j <= fre; j++) temp.pop_back();
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, 0, n, arr, temp, ans, target);
    sort(ans.begin(), ans.end());
    return ans;
}
