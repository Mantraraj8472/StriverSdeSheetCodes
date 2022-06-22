// problem link:
// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_758966?topList=striver-sde-sheet-problems&leftPanelTab=0

bool isValid(int i, int j, vector<vector<int> > &maze, vector<vector<int> > &visi, int n){
    return i >= 0 and j >= 0 and i < n and j < n and maze[i][j] and visi[i][j] == 0;
}

vector<vector<int> > moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(int i, int j, vector<vector<int> > &maze, vector<vector<int> > &visi, vector<vector<int> > &ans, int n){
    visi[i][j] = 1;
    if(i == n - 1 and j == n - 1){
        vector<int> rowAns;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++) rowAns.push_back(visi[r][c]);
        }
        ans.push_back(rowAns);
        visi[i][j] = 0;
        return;
    }
    
    for(auto mv : moves){
        int x = i + mv[0], y = j + mv[1];
        if(isValid(x, y, maze, visi, n)){
            solve(x, y, maze, visi, ans, n);
        }
    }
    visi[i][j] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int> > visi(n, vector<int>(n, 0)), ans;
    if(maze[0][0] == 0 or maze[n - 1][n - 1] == 0)
        return ans;
    solve(0, 0, maze, visi, ans, n);
    return ans;
}