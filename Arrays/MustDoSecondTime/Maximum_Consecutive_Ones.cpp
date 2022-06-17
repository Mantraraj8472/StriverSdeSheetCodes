// Problem link:
// https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_892994?topList=striver-sde-sheet-problems&leftPanelTab=0

int longestSubSeg(vector<int> &arr , int n, int k){
    int l = 0;
    int ct_0 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) ct_0++;
        if(ct_0 > k){
            while(arr[l] != 0) l++;
            l++;
            ct_0--;
        }
        ans = max(ans, i - l + 1);
    }
    return ans;
}
