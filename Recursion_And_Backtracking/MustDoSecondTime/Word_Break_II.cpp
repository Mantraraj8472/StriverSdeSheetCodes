// problem link:
// https://www.codingninjas.com/codestudio/problems/word-break-ii_983635?topList=striver-sde-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>

void solve(int ind, string &s, string &cur, string &subAns, vector<string> &ans, int n, unordered_map<string, bool> &hsh){
    if(ind == n){
//         if(cur.size() and hsh[cur]){
//             for(char c : cur) subAns.push_back(c);
//             ans.push_back(subAns);
//             for(char c : cur) subAns.pop_back();
//         }
        if(cur.size() == 0 and subAns.size()) ans.push_back(subAns);
        return;
    }
    cur.push_back(s[ind]);
    if(hsh[cur]){
        for(char c : cur) subAns.push_back(c);
        subAns.push_back(' ');
        string temp;
        solve(ind + 1, s, temp, subAns, ans, n, hsh);
        subAns.pop_back();
        for(char c : cur) subAns.pop_back();
    }
    solve(ind + 1, s, cur, subAns, ans, n, hsh);
    cur.pop_back();
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, bool> hsh;
    for(string &dict : dictionary)
        hsh[dict] = true;
    vector<string> ans;
    string cur;
    string subAns;
    int n = s.size();
    solve(0, s, cur, subAns, ans, n, hsh);
    return ans;
}