#include <bits/stdc++.h> 

struct triple{
    int sum, i, j;
};

bool cmp(triple a, triple b){
    return a.sum < b.sum;
}

bool isCommonInd(triple a, triple b){
    return a.i == b.i or a.i == b.j or a.j == b.i or a.j == b.j;
}

bool isCommonIndex(pair<int, int> p, int i, int j){
    return p.first == i or p.second == i or p.first == j or p.second == j;
}

string fourSum(vector<int> arr, int target, int n) {
    // 2 pointer approach
    // This is giving TLE
    // Time complexity is O(N * N * N)
//     sort(arr.begin(), arr.end());
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             int l = j + 1, r = n - 1;
//             int newTarget = target - arr[i] - arr[j];
//             while(l < r){
//                 int sum = arr[l] + arr[r];
//                 if(sum == newTarget) return "Yes";
//                 else if(sum < newTarget) l++;
//                 else r--;
//             }
//             int curJ = j;
//             while(j < n and arr[curJ] == arr[j]) j++;
//             j--;
//         }
//         int curI = i;
//         while(i < n and arr[curI] == arr[i]) i++;
//         i--;
//     }
//     return "No";
    
    // 3 pointer and binary search
    // This is also giving TLE
    // Time complexity is O(N * N * N * LogN)
//     sort(arr.begin(), arr.end());
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 int newTarget = target - arr[i] - arr[j] - arr[k];
//                 auto it = lower_bound(arr.begin() + k + 1, arr.end(), newTarget);
//                 if(it != arr.end() and *it == newTarget) return "Yes";
//             }
//         }
//     }
//     return "No";
    
    // Time complexity is O(N * N * LogN)
    /*
    Two Pointers With Sorting:
    We will create a temporary array temp[] to store the sum of all possible pairs.
    
    Now we sort this temp[] array. As each element of temp[] contains the sum of two elements so the     problem reduces to finding the two pairs in the temp[] such that their sum is equal to ‘target’.
    
    We can use two pointer technique to check whether there exist two pairs in the temp[] array that     gives the sum = ‘target’. 
    */
//     vector<triple> temp;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             temp.push_back({arr[i] + arr[j], i, j});
//         }
//     }
//     sort(temp.begin(), temp.end(), cmp);
//     int l = 0, r = temp.size() - 1;
//     while(l < r){
//         int sum = temp[l].sum + temp[r].sum;
//         if(sum == target and isCommonInd(temp[l], temp[r]) == false) return "Yes";
//         else if(sum < target) l++;
//         else r--;
//     }
//     return "No";
    
    // Time complexity is O(N * N)
    // Here we don't have to worry about multiple answers as we require max two pairs so one pair will come from two nested loops and another from hash map
    unordered_map<int, pair<int, int>> hsh;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            hsh[arr[i] + arr[j]] = {i, j};
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int newTarget = target - arr[i] - arr[j];
            if(hsh.find(newTarget) != hsh.end() and isCommonIndex(hsh[newTarget], i, j) == false) 
                return "Yes";
        }
    }
    return "No";
}
