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
	long long ans = power(x, n, m);
    return (int)ans;
}