#include <bits/stdc++.h> 
#define ll long long int

vector<vector<ll>> printPascal(int n) 
{
//     vector<vector<ll>> ans;
//     ans.push_back({1ll});
//     for(int i = 2; i <= n; i++){
//         vector<ll> temp;
//         temp.push_back(1ll);
//         int sz = ans.size() - 1;
//         for(int j = 1; j < ans[sz].size(); j++){
//             temp.push_back(ans[sz][j] + ans[sz][j - 1]);
//         }
//         temp.push_back(1ll);
//         ans.push_back(temp);
//     }
//     return ans;
    
    vector<vector<ll>> ans;
    for(int i = 0; i < n; i++){
        ll var = 1ll;
        vector<ll> temp;
        temp.push_back(var);
        for(int j = 1; j <= i; j++){
            var = (var * (i - j + 1)) / j;
            temp.push_back(var);
        }
        ans.push_back(temp);
    }
    return ans;
}
