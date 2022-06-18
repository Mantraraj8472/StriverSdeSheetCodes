// problem link:
// https://www.codingninjas.com/codestudio/problems/maximum-meetings_1062658?topList=striver-sde-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>
struct meet{
    int end;
    int pos;
    int start;
};

bool cmp(meet a, meet b){
    if(a.end != b.end) return a.end < b.end;
    return a.pos < b.pos;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<meet> meetings;
    int n = start.size();
    for(int i = 0; i < n; i++){
        meetings.push_back({end[i], i + 1, start[i]});
    }
    sort(meetings.begin(), meetings.end(), cmp);
    vector<int> ans;
    int curEnd = -1;
    for(int i = 0; i < n; i++){
        if(meetings[i].start > curEnd){
            ans.push_back(meetings[i].pos);
            curEnd = meetings[i].end;
        }
    }
    return ans;
}