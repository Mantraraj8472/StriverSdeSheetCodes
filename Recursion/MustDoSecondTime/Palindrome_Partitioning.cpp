// problem link:
// https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_799931?topList=striver-sde-sheet-problems&leftPanelTab=0

int palinDP(string &s, int i, int j, vector<vector<int>> dp){
    if(i >= j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = s[i - 1] == s[j - 1] ? palinDP(s, i + 1, j - 1, dp) : 0;
}

void solve(int ind, int n, vector<int> &partiInd, string &s, vector<vector<string>> &ans, vector<vector<int>> &dp){
    if(ind == n){
        vector<string> partiStrings;
        partiInd.push_back(n);
        for(int i = 1; i < partiInd.size(); i++){
            int sz = partiInd[i] - partiInd[i - 1];
            if(palinDP(s, partiInd[i - 1] + 1, partiInd[i], dp) == 0){
                partiInd.pop_back();
                return;
            }
            partiStrings.push_back(s.substr(partiInd[i - 1], sz));
        }
        partiInd.pop_back();
        ans.push_back(partiStrings);
        return;
    }
    solve(ind + 1, n, partiInd, s, ans, dp);
    partiInd.push_back(ind);
    solve(ind + 1, n, partiInd, s, ans, dp);
    partiInd.pop_back();
}

vector<vector<string>> partition(string &s) 
{
    vector<int> partiInd;
    partiInd.push_back(0);
    vector<vector<string>> ans;
    if(s.size() == 0) return {{}};
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    solve(1, n, partiInd, s, ans, dp);
    return ans;
}