// problem link:
// https://www.codingninjas.com/codestudio/problems/running-median_625409?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    multiset<int> left, right;
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(left.size() == 0){
            left.insert(cur);
            cout << cur << ' ';
            continue;
        }
        if(right.size() == 0){
            if(*(left.begin()) > cur){
                right.insert(*(left.begin()));
                left.erase(left.begin());
                left.insert(cur);
            }
            else right.insert(cur);
            cout << ((*(--left.end())) + (*(right.begin()))) / 2 << ' ';
            continue;
        }
        int lmax = *(--left.end()); // 4
        int rmin = *(right.begin()); // 5
        if(cur > rmin){
            if(left.size() == right.size()){
                right.erase(right.begin());
                left.insert(rmin);
                right.insert(cur);
            }
            else{
                right.insert(cur);
            }
        }
        else{
            if(left.size() == right.size()) left.insert(cur);
            else{
                if(cur > lmax) right.insert(cur);
                else{
                    right.insert(lmax);
                    left.erase(--left.end());
                    left.insert(cur);
                }
            }
        }
        if(i % 2 == 0){
            cout << *(--left.end()) << ' ';
        }
        else{
            cout << ((*(--left.end())) + (*(right.begin()))) / 2 << ' ';
        }
    }
}