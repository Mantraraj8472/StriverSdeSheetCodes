#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int ele1 = -1, ele2 = -1, fre1 = 0, fre2 = 0, n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == ele1) fre1++;
        else if(arr[i] == ele2) fre2++;
        else if(fre1 == 0){
            ele1 = arr[i];
            fre1 = 1;
        }
        else if(fre2 == 0){
            ele2 = arr[i];
            fre2 = 1;
        }
        else{
            fre1--;
            fre2--;
        }
    }
    vector<int> ans;
    fre1 = 0, fre2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele1) fre1++;
        else if(arr[i] == ele2) fre2++;
    }
    if(fre1 > n / 3) ans.push_back(ele1);
    if(fre2 > n / 3) ans.push_back(ele2);
    return ans;
}