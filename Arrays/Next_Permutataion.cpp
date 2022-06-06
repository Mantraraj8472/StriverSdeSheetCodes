#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    vector<int> ans = permutation;
    for(int i = n - 2; i >= 0; i--){
        if(ans[i] < ans[i + 1]){
            for(int j = n - 1; j >= 0; j--){
                if(ans[j] > ans[i]){
                    swap(ans[j], ans[i]);
                    break;
                }
            }
            reverse(ans.begin() + i + 1, ans.end());
            return ans;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}