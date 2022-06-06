#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    // Two pointer approach
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++){
        // Why this loop or why not loop for l?
        // Because we are damn sure that for all i < l arr[i] == 0 but we are not sure that arr[r] == 2 or not.
        while(r >= 0 and arr[r] == 2) r--;
        if(i == r + 1) break;
        if(arr[i] == 2){
            swap(arr[i], arr[r]);
            r--;
        }
        if(arr[i] == 0) {
            swap(arr[i], arr[l]);
            l++;
        }
    }
}