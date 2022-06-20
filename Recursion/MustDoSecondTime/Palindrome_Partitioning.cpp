bool isPalin(string &s, int n){
    for(int i = 0; i < n; i++){
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

void solve(int ind, int n, vector<int> &partiInd, string &s, vector<vector<string>> &ans){
    if(ind == n){
        vector<string> partiStrings;
        partiInd.push_back(n);
        string temp = s.substr(0, partiInd[0]);
        if(!isPalin(temp, temp.size())) {
            partiInd.pop_back();
            return;
        }
        partiStrings.push_back(temp);
        for(int i = 1; i < partiInd.size(); i++){
            int sz = partiInd[i] - partiInd[i - 1];
            string temp = s.substr(partiInd[i - 1], sz);
            if(!isPalin(temp, sz)){
                partiInd.pop_back();
                return;
            }
            partiStrings.push_back(temp);
        }
        partiInd.pop_back();
        ans.push_back(partiStrings);
        return;
    }
    solve(ind + 1, n, partiInd, s, ans);
    partiInd.push_back(ind);
    solve(ind + 1, n, partiInd, s, ans);
    partiInd.pop_back();
}

vector<vector<string>> partition(string &s) 
{
    vector<int> partiInd;
    vector<vector<string>> ans;
    
    if(s.size() == 0) return {{}};
    solve(1, s.size(), partiInd, s, ans);
    return ans;
}