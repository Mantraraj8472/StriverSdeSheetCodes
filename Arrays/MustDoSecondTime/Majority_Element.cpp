#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // Intuition or explanation:
    /*
    Here we can say that only one element will be there in whole array which appears more than n / 2 times.
    As if two elements are there which appears more than n /  2 times in an array of size n which contradicts.
    So we maintain the fre and ele, and atlast majority element is greater than all minority elements so fre is always positive for majority element as minority elements can make fre-- not more than fre++ for majority.
    So atlast we check that if that element appears more than n / 2 times and if it is then we return it.
    */ 
	int ele = 1e9, fre = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele) 
            fre++;
        else if(fre == 0){
            ele = arr[i];
            fre = 1;
        }
        else fre--;
    }
    if(fre > 0){
        fre = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == ele)
                fre++;
        if(fre > n / 2) 
            return ele;
        return -1;
    }
    return -1;
}