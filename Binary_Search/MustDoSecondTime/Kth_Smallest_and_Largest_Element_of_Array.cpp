// problem link:
// https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>

int parti(vector<int> &arr, int l, int r){
    // Let our pivot be last element
    int pivot = arr[r];
    int rc = r;
    r--;
    while(l <= r){
        if(arr[l] > pivot and arr[r] < pivot){
            swap(arr[l], arr[r]);
        }
        while(l <= r and arr[l] <= pivot) l++;
        while(l <= r and arr[r] > pivot) r--;
    }
    swap(arr[rc], arr[l]);
    return l;
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
// 	sort(arr.begin(), arr.end());
//     return {arr[k - 1], arr[n - k]};
    
    int ksmall, klarge;
    int l = 0, h = n - 1;
    while(l <= h){
        int pivot = parti(arr, l, h);
        if(pivot == k - 1){
            ksmall = arr[pivot];
            break;
        }
        if(pivot < k - 1){
            l = pivot + 1;
        }
        else {
            h = pivot - 1;
        }
    }
    l = 0, h = n - 1;
    while(l <= h){
        int pivot = parti(arr, l, h);
        if(pivot == n - k){
            klarge = arr[pivot];
            break;
        }
        if(pivot < n - k + 1){
            l = pivot + 1;
        }
        else{
            h = pivot - 1;
        }
    }
    return {ksmall, klarge};
}
