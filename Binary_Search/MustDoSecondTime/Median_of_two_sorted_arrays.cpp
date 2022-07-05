// problem link:
// https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

double median(vector<int> a, vector<int> b)
{
    if(a.size() > b.size()) swap(a, b);
    int n = a.size(), m = b.size();
    int l = 0, h = n - 1, mid;
    int midi = (m + n + 1) / 2; 
    int tot = (m + n); 
    // for handling last cases when one of the array gets over
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    while(l <= h){
        mid = (l + h) >> 1;
        int req = midi - mid - 1;
        if(req < 0) {
            h = mid - 1;
            continue;
        }
        if(req == 0){
            if(a[mid] <= b[0]){
                if(tot & 1) return a[mid];
                else return (a[mid] + b[0]) / 2.0;
            }
            else h = mid - 1;
            continue;
        }
        int lastb = b[req - 1];
        if(a[mid] <= b[req] and lastb <= a[mid + 1]){
            if(tot & 1) return max(a[mid], lastb);
            else return (max(a[mid], lastb) + min(a[mid + 1], b[req])) / 2.0;
        }
        else{
            if(a[mid] > b[req]) h = mid - 1;
            else l = mid + 1;
        }
    }
    if(tot & 1) return b[midi - 1];
    return (a[0] + b[midi - 1]) / 2.0;
}
