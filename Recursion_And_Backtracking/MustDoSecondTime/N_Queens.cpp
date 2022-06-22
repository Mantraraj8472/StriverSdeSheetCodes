// problem link:
// https://www.codingninjas.com/codestudio/problems/n-queens_759332?topList=striver-sde-sheet-problems&leftPanelTab=0

void updateCanPlace(vector<vector<int>> &canPlace, int row, int col, int val, int n){
    for(int i = row + 1; i < n; i++) 
        canPlace[i][col] += val ? 1 : -1;
    int i = row + 1, j = col - 1;
    while(i < n and j >= 0){
        canPlace[i][j] += val ? 1 : -1;
        i++;
        j--;
    }
    i = row + 1, j = col + 1;
    while(i < n and j < n){
        canPlace[i][j] += val ? 1 : -1;
        i++;
        j++;
    }
}

void solve(int row, vector<vector<int>> &temp, vector<vector<int>> &ans, vector<vector<int>> &canPlace, int n){
    if(row == n){
        vector<int> rowMat;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) rowMat.push_back(temp[i][j]);
        }
        ans.push_back(rowMat);
        return;
    }
    for(int col = 0; col < n; col++){
        if(canPlace[row][col] == 1){
            temp[row][col] = 1;
            updateCanPlace(canPlace, row, col, 0, n);
            solve(row + 1, temp, ans, canPlace, n);
            updateCanPlace(canPlace, row, col, 1, n);
            temp[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> temp(n, vector<int>(n, 0)), ans, canPlace(n, vector<int>(n, 1));
    
    solve(0, temp, ans, canPlace, n);
    return ans;
}