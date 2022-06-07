#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    // Here we can use the advantage of having range of numbers which is [1, n - 1] so we can use this array itself as hash array.
    // And we use hashing by adding n to the arr[ele] and if that arr[ele] > 2 * n means this is repeated.
	for(int i = 0; i < n; i++){
        int ele = arr[i] % n;
        arr[ele] += n;
        if(arr[ele] > 2 * n) return ele;
    }
}
