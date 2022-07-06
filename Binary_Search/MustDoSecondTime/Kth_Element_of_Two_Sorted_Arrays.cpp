// problem link:
// https://www.codingninjas.com/codestudio/problems/ninja-and-ladoos_1112629?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // This approach will give TLE
//     int ans, r1i = 0, r2i = 0;
//     row1.push_back(INT_MAX);
//     row2.push_back(INT_MAX);
//     while(k--){
//         if(row1[r1i] <= row2[r2i]) 
//             ans = row1[r1i++];
//         else 
//             ans = row2[r2i++];
//     }
//     return ans;
    
    n = row1.size();
    m = row2.size();
    row1.push_back(INT_MAX);
    row2.push_back(INT_MAX);
    if(n > m) {
        swap(row1, row2);
        swap(n, m);
    }
    int l = 0, h = n - 1, mid;
    while(l <= h){
        mid = (l + h) >> 1;
        int req = k - mid - 1;
        if(req < 0){
            h = mid - 1;
            continue;
        }
        if(req > m){
            l = mid + 1;
            continue;
        }
        if(req == 0){
            if(row1[mid] <= row2[0]) return row1[mid];
            h = mid - 1;
            continue;
        }
        int lastRow2 = row2[req - 1];
        if(row1[mid] <= row2[req] and lastRow2 <= row1[mid + 1])
            return max(row1[mid], lastRow2);
        if(row1[mid] > row2[req]) {
            h = mid - 1;
            continue;
        }
        l = mid + 1;
    }
    return row2[k - 1];
}