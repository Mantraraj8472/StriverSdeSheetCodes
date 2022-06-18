// problem link:
// https://www.codingninjas.com/codestudio/problems/maximum-activities_1062712?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int curEnd = -1;
    int n = start.size();
    vector<pair<int, int>> startEnd(n);
    for(int i = 0; i < n; i++){
        startEnd[i].first = finish[i];
        startEnd[i].second = start[i];
    }
    sort(startEnd.begin(), startEnd.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(startEnd[i].second >= curEnd){
            curEnd = startEnd[i].first;
            ans++;
        }
    }
    return ans;
}