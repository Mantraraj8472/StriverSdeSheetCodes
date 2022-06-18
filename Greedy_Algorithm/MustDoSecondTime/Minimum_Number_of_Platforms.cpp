// problem link:
// https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400?topList=striver-sde-sheet-problems

int calculateMinPatforms(int at[], int dt[], int n) {
//     sort(at, at + n);
//     sort(dt, dt + n);
//     int maxTrains = 0;
//     int ai = 0, di = 0;
//     int ans = INT_MIN;
//     while(ai < n and di < n){
//         if(at[ai] <= dt[di]){
//             ai++;
//             maxTrains++;
//             ans = max(ans, maxTrains);
//         }
//         else{
//             di++;
//             maxTrains--;
//         }
//     }
//     ans += (n - ai);
//     return ans;
    
    // In O(N + 2360) time and almost constant O(2361) space
    // We are storing the duration of each train at the platform using concept of prefix sum
    vector<int> platforms(2361, 0);
    for(int i = 0; i < n; ++i){
        platforms[at[i]]++;
        platforms[dt[i] + 1]--;
    }
    // Making prefix sum
    int maxTrains = 0;
    for(int i = 1; i < 2360; ++i){
        platforms[i] += platforms[i - 1];
        maxTrains = max(maxTrains, platforms[i]);
    }
    return maxTrains;
}