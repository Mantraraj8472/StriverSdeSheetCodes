// problem link:
// https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273?topList=striver-sde-sheet-problems&leftPanelTab=0

bool canColor(int col, int r, vector<int> adj[], vector<int> &color){
    for(int child : adj[r]){
        if(color[child] == col) return false;
    }
    return true;
}

bool solve(int r, vector<int> adj[], vector<int> &color, int m, vector<int> &visi){
    visi[r] = 1;
    bool ans = true;
    for(int child : adj[r]){
        if(color[child] == 0){
            bool curChildAns = false;
            for(int i = 1; i <= m; i++){
                if(canColor(i, child, adj, color)){
                    color[child] = i;
                    curChildAns |= solve(child, adj, color, m, visi);
                    if(curChildAns) break;
                    color[child] = 0;
                }
            }
            ans &= curChildAns;
        }
    }
    return ans;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> color(n, 0), visi(n, 0);
    color[0] = 1;
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(visi[i] == 0) {
            color[i] = 1;
            ans &= solve(i, adj, color, m, visi);
        }
    }
    return ans ? "YES" : "NO";
}