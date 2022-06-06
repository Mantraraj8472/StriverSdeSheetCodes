#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// row - 1 is used for checking for each column correspoding to that cell
    // col - 1 is used for checking for each row corresponding to that cell
    // matrix[0][0] denotes for col 1 only and for row 1 I will use variable for this
    int row = 0, col = 0, n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 1e9;
                matrix[0][j] = 1e9;
                if(i == 0) row = 1;
                if(j == 0) col = 1;
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][0] == 2 or matrix[0][j] == 2) 
                matrix[i][j] = 0;
        }
    }
    if(row) 
        for(int j = 0; j < m; j++) matrix[0][j] = 0;
    else 
        for(int j = 0; j < m; j++)
            if(matrix[0][j] == 2) matrix[0][j] = 0;
    if(col) 
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
    else 
        for(int i = 0; i < n; i++)
            if(matrix[i][0] == 2) matrix[i][0] = 0;
}