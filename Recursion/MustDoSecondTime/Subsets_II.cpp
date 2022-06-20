// problem link:
// https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

void solve(int ind, vector<int> &arr, vector<int> &temp, set<vector<int>> &tempAns){
    if(ind == 0){
        vector<int> copy = temp;
        sort(copy.begin(), copy.end());
        tempAns.insert(copy);
        return;
    }
    solve(ind - 1, arr, temp, tempAns);
    temp.push_back(arr[ind - 1]);
    solve(ind - 1, arr, temp, tempAns);
    temp.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Using sets
    set<vector<int>> tempAns;
    vector<int> temp;
    vector<vector<int>> ans;
    solve(n, arr, temp, tempAns);
    for(auto i : tempAns) ans.push_back(i);
    return ans;
}