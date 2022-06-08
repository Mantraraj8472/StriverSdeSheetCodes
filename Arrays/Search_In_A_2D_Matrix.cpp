#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int n, int m, int target) {
    int row = -1;
    int l = 0, h = mat.size() - 1, mid;
    while(l <= h){
        mid = (l + h) >> 1;
        if(mat[mid][0] == target) return true;
        if(mat[mid][0] < target){
            row = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }
    if(row == -1) 
        return false;
    l = 0, h = mat[0].size() - 1;
    while(l <= h){
        mid = (l + h) >> 1;
        if(mat[row][mid] == target) return true;
        if(mat[row][mid] < target) l = mid + 1;
        else h = mid - 1;
    }
    return false;
}