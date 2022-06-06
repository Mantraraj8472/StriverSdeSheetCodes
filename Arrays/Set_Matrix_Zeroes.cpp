#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// row - 1 is used for checking for each column correspoding to that cell
    // col - 1 is used for checking for each row corresponding to that cell
    // As there will be conflict in case of matrix[0][0] we can use two var for row 1 and col 1
    int row = 0, col = 0, n = matrix.size(), m = matrix[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if(i == 0) row = 1;
                if(j == 0) col = 1;
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][0] == 0 or matrix[0][j] == 0) 
                matrix[i][j] = 0;
        }
    }
    if(row) 
        for(int j = 0; j < m; j++) matrix[0][j] = 0;
    if(col) 
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
}