#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    // Two pointer approach
//     int l = 0, r = n - 1;
//     for(int i = 0; i < n; i++){
//         // Why this loop or why not loop for l?
//         // Because we are damn sure that for all i < l arr[i] == 0 but we are not sure that arr[r] == 2 or not.
//         while(r >= 0 and arr[r] == 2) r--;
//         if(i == r + 1) break;
//         if(arr[i] == 2){
//             swap(arr[i], arr[r]);
//             r--;
//         }
//         if(arr[i] == 0) {
//             swap(arr[i], arr[l]);
//             l++;
//         }
//     }

    // Three Pointer approach
    /*
    :)) This is same as 2 pointer the only difference is here mid works as of i. 
    This approach is based on Dutch National Flag Problem
    In this l = 0, mid = 0 and r = n - 1
    This algo is based on fact that all elements from 0 to l - 1 are 0 and r + 1 to n - 1 are 1.
    */
    int l = 0, mid = 0, r = n - 1;
    while(mid <= r){
        if(arr[mid] == 0) swap(arr[l++], arr[mid++]);
        else if(arr[mid] == 2) swap(arr[mid], arr[r--]);
        else mid++;
    }
}