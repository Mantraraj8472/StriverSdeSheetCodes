// problem link:
// https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

bool cmp(vector<int> a, vector<int> b){
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] < b[0];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int ans = 0, n = jobs.size(), maxi = 1;
    for(int i = 0; i < n; i++) maxi = max(maxi, jobs[i][0]);
    set<int> st;
    for(int i = 1; i <= maxi; i++) st.insert(i);
    for(int i = 0; i < n; i++){
        auto ub = st.upper_bound(jobs[i][0]);
        if(ub == st.begin()) continue;
        ub--;
        st.erase(ub);
        ans += jobs[i][1];
    }
    return ans;
}
