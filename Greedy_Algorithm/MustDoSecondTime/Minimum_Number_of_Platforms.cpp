// problem link:
// https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400?topList=striver-sde-sheet-problems

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int maxTrains = 0;
    int ai = 0, di = 0;
    int ans = INT_MIN;
    while(ai < n and di < n){
        if(at[ai] <= dt[di]){
            ai++;
            maxTrains++;
            ans = max(ans, maxTrains);
        }
        else{
            di++;
            maxTrains--;
        }
    }
    ans += (n - ai);
    return ans;
}