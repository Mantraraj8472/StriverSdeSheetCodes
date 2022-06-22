// problem link:
// https://www.codingninjas.com/codestudio/problems/print-permutations-string_758958?topList=striver-sde-sheet-problems&leftPanelTab=0

void solve(int ind, string &temp, vector<string> &ans, int n, vector<int> &visi, string &s){
    if(ind == n + 1){
        ans.push_back(temp);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(visi[i] == 0){
            temp.push_back(s[i - 1]);
            visi[i] = 1;
            solve(ind + 1, temp, ans, n, visi, s);
            visi[i] = 0;
            temp.pop_back();
        }
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    string temp;
    int n = s.size();
    vector<int> visi(n + 1, 0);
    solve(1, temp, ans, n, visi, s);
    return ans;
}