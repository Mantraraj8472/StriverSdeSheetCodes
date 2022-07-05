// problem link:
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> merge(vector<int> &l, vector<int> &r){
    vector<int> ans;
    int li = 0, ri = 0;
    while(li < l.size() and ri < r.size()){
        if(l[li] < r[ri]) ans.push_back(l[li++]);
        else ans.push_back(r[ri++]);
    }
    while(li < l.size()) ans.push_back(l[li++]);
    while(ri < r.size()) ans.push_back(r[ri++]);
    return ans;
}

vector<int> solve(vector<vector<int>> &karr, int l, int r){
    if(l == r) return karr[l];
    int mid = (l + r) >> 1;
    vector<int> left = solve(karr, l, mid);
    vector<int> right = solve(karr, mid + 1, r);
    return merge(left, right);
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Naive approach
//     vector<int> ans;
//     for(int i = 0; i < k; i++){
//         for(int ele : kArrays[i]) ans.push_back(ele);
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
    
    // Divide and conquer approach
    return solve(kArrays, 0, k - 1);
}
