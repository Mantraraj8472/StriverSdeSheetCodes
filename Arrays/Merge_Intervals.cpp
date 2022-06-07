#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    int st = intervals[0][0], ed = intervals[0][1];
    for(int i = 1; i < n; i++){
        if(intervals[i][0] <= ed){
            ed = max(intervals[i][1], ed);
        }
        else{
            ans.push_back({st, ed});
            st = intervals[i][0];
            ed = intervals[i][1];
        }
    }
    ans.push_back({st, ed});
    return ans;
}
