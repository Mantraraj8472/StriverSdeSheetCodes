// problem link:
// https://www.codingninjas.com/codestudio/problems/nth-root-of-m_1062679?topList=striver-sde-sheet-problems&leftPanelTab=0

#define ld long double

long double mult(long double mid, int n){
    long double ans = 1.0;
    for(int i = 1; i <= n; i++)
        ans = ans * mid;
    return ans;
}

double findNthRootOfM(int n, long long m) {
//     long double l = 0.0, h = m * 1.0, mid, dec = 1e-9, ans;
//     while(l + dec < h){
//         mid = (l + h) / 2.0;
//         if(mult(mid, n) < m) l = mid;
//         else h = mid;
//     }
//     return l;
    
    // Newton Raphson method
    // Reference link: https://www.youtube.com/watch?v=rCoABot_tIE
    // x = m ^ (1 / n)
    // x ^ n = m
    // x ^ n - m = 0
    // so f(x) = x ^ n - m
    // We want to find x such that f(x) = 0
    // We make some initial guess we follow procedure given by newton raphson method.
    // Next approximate root can be derived from previous root by equation:
    // x2 = x1 - f(x1) / f'(x1)
    // Where f'(x) = n * x ^ (n - 1)
    // by solving we get x2 = (x1 ^ n) * n + m / n * x1 ^ n
    // We procees till our difference between x is less than 1e-6
    
    ld error = 1e-6;
    ld diff = 1e18; // any random greater than error
    ld guess = 5;
    while(diff > error){
        ld nextApprox = (pow(guess, n) * (n - 1) + m) / (n * pow(guess, n - 1));
        diff = abs(guess - nextApprox);
        guess = nextApprox;
    }
    return guess;
}
