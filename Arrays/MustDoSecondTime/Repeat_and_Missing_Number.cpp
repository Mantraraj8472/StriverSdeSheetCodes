#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Basic concept is that use this given array as a hash array as the elements of the array lies in the range of [1, N]
    
    for(int i = 0; i < n; i++){
        int ele = arr[i] % (n + 1);
        arr[ele - 1] += (n + 1);
    }
    pair<int, int> ans;
    for(int i = 0; i < n; i++){
        if(arr[i] <= n) ans.first = i + 1;
        else if(arr[i] >= (2 * (n + 1))) ans.second = i + 1;
    }
    return ans;

    // Another method is using mathematical formula
    /*
    sum of 1 to n is n * (n + 1) / 2 --> s1n
    sum of 1 ^ 2 to n ^ 2 is n * (n + 1) * (2 * n + 1) / 6 --> ss1n
    sum of all elements of given array --> sa1n
    sum of squares of all elements of given array --> ssa1n
    Let repeated be R and missing be X
    sa1n - s1n = R - M 
    ssa1n - ss1n = R * R - M * M
                 = (R - M) * (R + M)
                 = (sa1n - s1n) * (R + M)
    so now we have R - M and R + M so we can easily find R and M.
    */
    int s1n = (n * (n + 1)) / 2;
    int ss1n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long int sa1n = 0ll, ssa1n = 0ll;
    for(int i = 0; i < n; i++){
        sa1n += arr[i];
        ssa1n += (arr[i] * arr[i]);
    }
    long long int diffrm = sa1n - s1n;
    long long int diffsrm = ssa1n - ss1n;
    long long int sumrm = diffsrm / diffrm;
    return {(sumrm - diffrm) / 2, (sumrm + diffrm) / 2};
}
