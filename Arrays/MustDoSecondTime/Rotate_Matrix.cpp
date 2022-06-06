#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(n == 1 or m == 1) return;
    int l = 0, r = m - 1, u = 0, d = n - 1;
    int prev = mat[0][0];
    int cur = prev;
    while(l < r and u < d){
        prev = mat[u + 1][l];
        for(int j = l; j <= r; j++){
            cur = mat[u][j];
            mat[u][j] = prev;
            prev = cur;
        }
        u++; 
        for(int i = u; i <= d; i++){
            cur = mat[i][r];
            mat[i][r] = prev;
            prev = cur;
        }
        r--; 
        for(int j = r; j >= l; j--){
            cur = mat[d][j];
            mat[d][j] = prev;
            prev = cur;
        }
        d--; 
        for(int i = d; i >= u; i--){
            cur = mat[i][l];
            mat[i][l] = prev;
            prev = cur;
        }
        l++;
    }
}