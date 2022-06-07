#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Basic concept is that use this given array as a hash array as the elements of the array lies in the range of [1, N]
    
    for(int i = 0; i < n; i++){
        int ele = arr[i] % (n + 1);
        arr[ele - 1] += (n + 1);
    }
    pair<int, int> ans;
    for(int i = 0; i < n; i++){
        if(arr[i] <= n) ans.first = i + 1;
        else if(arr[i] >= (2 * (n + 1))) ans.second = i + 1;
    }
    return ans;
}
