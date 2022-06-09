#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    vector<int> ind(256, -1);
    int l = 0, ans = 0, n = input.size();
    for(int i = 0; i < n; i++){
        if(ind[input[i]] >= 0){
            ans = max(ans, i - l);
            for(int j = l; j < ind[input[i]]; j++)
                ind[input[j]] = -1;
            l = ind[input[i]] + 1;
        }
        ind[input[i]] = i;
    }
    ans = max(ans, n - l);
    return ans;
}