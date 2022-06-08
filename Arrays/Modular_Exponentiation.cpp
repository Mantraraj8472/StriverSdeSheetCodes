#include <bits/stdc++.h> 

long long power(long long a, long long b, long long mod){
    if(b == 0) 
        return 1ll;
    long long var = power(a, b / 2, mod) % mod;
    if(b & 1) 
        return (a * ((var * var) % mod)) % mod;
    return (var * var) % mod;
}

int modularExponentiation(int x, int n, int m) {
// 	long long ans = power(x, n, m);
//     return (int)ans;
    
    // Above method has time complexity of O(logb) and also space complexity of O(logb) which is a stack space.
    // So by using iterative approach we can eleminate this stack spae
    long long ans = 1ll;
    long long xc = x;
    while(n){
        if(n & 1)
            ans = (1ll * ans * xc) % m;
        n >>= 1;
        xc = (1ll * xc * xc) % m;
    }
    return ans;
}