// problem link:
// https://www.codingninjas.com/codestudio/problems/sudoku_758961?topList=striver-sde-sheet-problems&leftPanelTab=1

bool canPlace(int no, int i, int j, int mat[9][9]){
    for(int row = 0; row < 9; row++){
        if(mat[row][j] == no) return false;
    }
    for(int col = 0; col < 9; col++){
        if(mat[i][col] == no) return false;
    }
    int row = (i / 3) * 3;
    int col = (j / 3) * 3;
    for(int r = row; r < row + 3; r++){
        for(int c = col; c < col + 3; c++){
            if(mat[r][c] == no) return false;
        }
    }
    return true;
}

bool solve(int i, int j, int mat[9][9]){
    if(i == 9){
        return true;
    }
    if(j == 9){
        return solve(i + 1, 0, mat);
    }
    if(mat[i][j] != 0){
        return solve(i, j + 1, mat);
    }
    bool ans = false;
    for(int no = 1; no <= 9; no++){
        if(canPlace(no, i, j, mat)){
            mat[i][j] = no;
            ans |= solve(i, j + 1, mat);
            mat[i][j] = 0;
            if(ans) return ans;
        }
    }
    return ans;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(0, 0, matrix);
}
