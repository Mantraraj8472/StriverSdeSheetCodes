// problem link:
// https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

#define ll long long

// Here we can check if possible to divide chapters such that ayush gives atmost mid unit of time on a single day
bool canPossible(ll mid, int n, int m, vector<int> &time){
    ll days = 0ll;
    ll tim = 0ll;
    for(ll i = 0ll; i < m; i++){
        if(tim + time[i] <= mid){
            tim += time[i];
        }
        else{
            days++;
            tim = time[i];
        }
    }
    days++;
    return days <= n;
}

ll ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	ll sum = 0;
    ll maxi = time[0];
    for(ll i = 0; i < m; i++) {
        sum += time[i];
        maxi = max(maxi, 0ll + time[i]);
    }
    
    // so we can say that minimum amount of time ayush has to give his max of time taken by all chapters and maximum amount of time when he reads all chapters in a single day which is sum of all chapters time.
    
    // So we can apply binary search to time
    ll l = maxi, h = sum, mid;
    while(l < h){
        mid = (l + h) / 2ll;
        if(canPossible(mid, n, m, time)){
            h = mid;
        }
        else{
            l = mid + 1ll;
        }
    }
    return h;
}