// problem link:
// https://www.codingninjas.com/codestudio/problems/rotting-oranges_701655?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visi){
    return x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1 and visi[x][y] == 0;
}

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, int>> q;
    vector<vector<int>> visi(n, vector<int>(m, 0));
    bool isOrange = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
                visi[i][j] = 1;
                isOrange = true;
            }
            else if(grid[i][j] == 0)
                visi[i][j] = 1;
            else
                isOrange = true;
        }
    }
    int time = 0;
    while(q.size()){
        time++;
        int sz = q.size();
        while(sz--){
            auto cur = q.front();
            q.pop();
            for(auto mv : moves){
                int x = cur.first + mv.first;
                int y = cur.second + mv.second;
                if(valid(x, y, n, m, grid, visi)){
                    visi[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visi[i][j] == 0)
                return -1;
        }
    }
    return isOrange ? --time : 0;
}