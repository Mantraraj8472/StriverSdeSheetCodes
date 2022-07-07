// problem link:
// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

map<char, int> hsh = {{'(', -1}, {')', 1}, {'{', -2}, {'}', 2}, {'[', -3}, {']', 3}};

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(char c : s){
        if(hsh[c] < 0){
            st.push(c);
            continue;
        }
        if(st.size() == 0 or hsh[st.top()] + hsh[c] != 0)
            return false;
        st.pop();
    }
    return st.size() == 0 ? true : false;
}