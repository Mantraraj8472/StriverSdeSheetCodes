// Problem link:
// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_1102307?topList=striver-sde-sheet-problems&leftPanelTab=0

int removeDuplicates(vector<int> &arr, int n) {
	int ans = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]) continue;
        else ans++;
    }
    return ans;
    
    // With array modification in O(N) using two pointer approach
    int j = 1;
    for(int i = 1; i < n; i++){
       if(arr[i] != arr[i - 1])
           arr[j++] = arr[i];
       else 
           continue;
    }
}