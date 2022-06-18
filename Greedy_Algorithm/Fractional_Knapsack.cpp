// problem link:
// https://www.codingninjas.com/codestudio/problems/fractional-knapsack_975286?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    vector<pair<double, int>> fractions(n, {0.0, 0});
    for(int i = 0; i < n; ++i){
        fractions[i].first = (items[i].second * 1.0) / items[i].first;
        fractions[i].second = items[i].first;
    }
    sort(fractions.begin(), fractions.end());
    double ans = 0.0;
    for(int i = n - 1; i >= 0 and w; i--){
        ans += fractions[i].first * (min(w, fractions[i].second));
        w -= min(w, fractions[i].second);
        
    }
    return ans;
}