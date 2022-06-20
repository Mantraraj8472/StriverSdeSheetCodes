// problem link:
// https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence_1112626?topList=striver-sde-sheet-problems

// But actually this question is of math not of recursion as per given constraints :(

#include <bits/stdc++.h>

void nextPermutation(string &s, int n){
    for(int i = n - 2; i >= 0; i--){
        if(s[i] < s[i + 1]){
            int swInd = i + 1;
            for(int j = n - 1; j > i; j--){
                if(s[j] > s[i] and s[j] < s[swInd]) swInd = j;
            }
            swap(s[i], s[swInd]);
            reverse(s.begin() + i + 1, s.end());
            return;
        }
    }
    reverse(s.begin(), s.end());
    return;
}

string kthPermutation(int n, int k) {
    // BRUTE FORCE WILL GIVE TLE
//     string ans;
//     for(int i = 1; i <= n; i++) ans.push_back(i + '0');
//     while(--k){
//         nextPermutation(ans, n);
//     }
//     return ans;
    
    vector<int> fact(11, 1);
    for(int i = 2; i <= 10; i++)
        fact[i] = fact[i - 1] * i;
    string ans;
    vector<int> visi(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int posPerm = fact[n - i];
        int ct = ceil((1.0 * k) / posPerm);
        int passed = 0;
        int curVal;
        for(int j = 1; j <= n; j++){
            if(visi[j] == 0) passed++;
            if(passed == ct) {
                visi[j] = 1;
                curVal = j;
                break;
            }
        }
        ans.push_back(curVal + '0');
        k -= ((ct - 1) * fact[n - i]);
    }
    return ans;
}
