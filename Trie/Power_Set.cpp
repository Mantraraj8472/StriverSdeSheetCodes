// problem link:
// https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0

void solve(int ind, vector<int> &v, int n, vector<int> &temp, vector<vector<int>> &ans){
    if(ind == n + 1){
        ans.push_back(temp);
        return;
    }
    solve(ind + 1, v, n, temp, ans);
    temp.push_back(v[ind - 1]);
    solve(ind + 1, v, n, temp, ans);
    temp.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<int> temp;
    vector<vector<int>> ans;
    int n = v.size();
    solve(1, v, n, temp, ans);
    return ans;
}