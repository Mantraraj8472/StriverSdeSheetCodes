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
//     set<vector<int>> tempAns;
//     vector<int> temp;
//     vector<vector<int>> ans;
//     solve(n, arr, temp, tempAns);
//     for(auto i : tempAns) ans.push_back(i);
//     return ans;
    
    // Iterative without bitmasking
    // We can treat the duplicate elements as special elements. For example, if we have duplicate elements (5, 5), instead of treating them as two elements that are duplicate, we can treat it as one special element 5, but this element has more than two choices: you can either NOT put it into the subset, or put ONE 5 into the subset, or put TWO 5s into the subset. 
    // So if A[i] has a frequency of ‘F’, then there are F+1 choices.
    // Therefore, we are given an array (a1, a2, a3, ..., an) with each of them appearing (k1, k2, k3, ..., kn) times, the number of subsets is (k1+1)(k2+1)...(kn+1).
    vector<vector<int>> ans;
    ans.push_back({});
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        int curI = i;
        int fre = 0;
        while(i < n and arr[i] == arr[curI]) i++, fre++;
        i--;
        int curSz = ans.size();
        for(int k = 0; k < curSz; k++){
            vector<int> subset = ans[k];
            for(int j = 1; j <= fre; j++){
                subset.push_back(arr[curI]);
                ans.push_back(subset);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}