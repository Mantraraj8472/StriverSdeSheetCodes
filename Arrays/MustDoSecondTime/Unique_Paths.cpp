#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>> &dp){
    if(i < 0 or j < 0) return 0;
    if(i == 1 and j == 1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
}

int uniquePaths(int m, int n) {
    // Recursive way
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
// 	return solve(m, n, dp);
    
    // Iterative way
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     dp[1][1] = 1;
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(i == 1 and j == 1) continue;
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     return dp[m][n];
    
    // Iterative space optimised
//     vector<int> cur(n + 1, 0), prev(n + 1, 0);
//     cur[1] = 1;
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(i == 1 and j == 1) continue;
//             cur[j] = cur[j - 1] + prev[j];
//         }
//         prev = cur;
//     }
//     return prev[n];
    
    // Single array space optimisation approach 
//     vector<int> dp(n + 1, 0);
//     dp[1] = 1;
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(i == 1 and j == 1) continue;
//             dp[j] += dp[j - 1];
//         }
//     }
//     return dp[n];
    
    // Mathematical approach
    int downSteps = m - 1, rightSteps = n - 1;
    // So here we can say that we have m + n space and we have to arrange m and n people of similar kind. So total number of ways     are C(m + n, m or n)
    int ans = 1;
    for(int i = 1; i <= min(downSteps, rightSteps); i++){
        ans = (ans * (downSteps + rightSteps - i + 1)) / i;
    }
    return ans;
}