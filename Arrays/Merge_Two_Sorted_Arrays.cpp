#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i1 = m - 1, i2 = n - 1, ifi = m + n - 1;
    
    while(i2 >= 0){
        if((i1 >= 0 ? arr1[i1] : INT_MIN) >= arr2[i2])
            arr1[ifi--] = arr1[i1--];
        else 
            arr1[ifi--] = arr2[i2--];
    }
    return arr1;
}