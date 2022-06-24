// problem link:
// https://www.codingninjas.com/codestudio/problems/matrix-median_873378?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

bool canMedian(int median, vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    int ct = 0;
    for(int i = 0; i < n; i++){
        int l = 0, h = m - 1, mid, rowCt = -1;
        while(l <= h){
            mid = (l + h) >> 1;
            if(matrix[i][mid] <= median){
                rowCt = mid;
                l = mid + 1;
            }
            else 
                h = mid - 1;
        }
        ct += rowCt + 1;
    }
    return ((n * m) / 2) < ct;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Time complexity is O(Log(1e5) * N * Log(M))
    int n = matrix.size(), m = matrix[0].size();
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mini = min(mini, matrix[i][j]);
            maxi = max(maxi, matrix[i][j]);
        }
    }
    int l = mini, h = maxi, mid, ans;
    while(l <= h){
        mid = (l + h) >> 1;
        if(canMedian(mid, matrix)){
            ans = mid;
            h = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return ans;
    
    // Another approach is to solve it by the concept or merge part in mergeSort. That is we maintain the count by checking for first element of each row that which one is smallest and accordingly maintain the count variable.
}