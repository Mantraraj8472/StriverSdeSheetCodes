#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Basic concept is that use this given array as a hash array as the elements of the array lies in the range of [1, N]
    
//     for(int i = 0; i < n; i++){
//         int ele = arr[i] % (n + 1);
//         arr[ele - 1] += (n + 1);
//     }
//     pair<int, int> ans;
//     for(int i = 0; i < n; i++){
//         if(arr[i] <= n) ans.first = i + 1;
//         else if(arr[i] >= (2 * (n + 1))) ans.second = i + 1;
//     }
//     return ans;

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
    // long long int s1n = 0ll + (n * (n + 1ll)) / 2;
    // long long int ss1n = 0ll + (n * (n + 1ll) * (2 * n + 1ll)) / 6ll;
    // long long int sa1n = 0ll, ssa1n = 0ll;
    // for(int i = 0; i < n; i++){
    //     sa1n += arr[i];
    //     ssa1n += (arr[i] * arr[i]);
    // }
    // long long int diffrm = sa1n - s1n;
    // long long int diffsrm = ssa1n - ss1n;
    // long long int sumrm = diffsrm / diffrm;
    // return {(sumrm - diffrm) / 2, (sumrm + diffrm) / 2};

    // Another method is using xor 
    /*
    xor1n = 1 ^ 2 ^ ... ^ n
    xora1n = arr[0] ^ arr[1] ^ ... ^ arr[n - 1]
    xor = xor1n ^ xora1n
    xor = R ^ M (as all gets cancelled out)

    Now if any bit (say ith) is set in xor then that bit is either set in R or M.
    So separate all elements from array into two parts one in which ith bit is set and another in which ith bit is not set.
    Same for all elements from 1 to N.
    And now make xor of all elements which are in the same bucket and one of them will be R and one will be M.
    We can check it by iterating again in the array.
    */
    
    int xor1n = 0, xora1n = 0;
    for(int i = 0; i < n; i++){
        xor1n ^= (i + 1);
        xora1n ^= (arr[i]);
    }
    int xorrm = xor1n ^ xora1n;
    int bit = 0;
    for(int i = 0; i <= 30; i++){
        if(((1 << i) & xorrm) > 0){
            bit = i;
            break;
        }
    }
    int var0 = 0, var1 = 0;
    for(int i = 0; i < n; i++){
        if(((1 << bit) & arr[i]) > 0) var1 ^= arr[i];
        else var0 ^= arr[i];
        if(((1 << bit) & (i + 1)) > 0) var1 ^= (i + 1);
        else var0 ^= (i + 1);
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == var0) return {var1, var0};
        else if(arr[i] == var1) return {var0, var1};
    }
}
