class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int l = j + 1, r = n - 1;
                int newTarget = target - arr[i] - arr[j];
                while(l < r){
                    int curSum = arr[l] + arr[r];
                    if(newTarget == curSum){
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        int curL = l;
                        while(l < r and arr[curL] == arr[l]) l++;
                        int curR = r;
                        while(l < r and arr[curR] == arr[r]) r--;
                    }
                    else if(curSum < newTarget) l++;
                    else r--;
                }
                int curJ = j;
                while(j < n and arr[curJ] == arr[j]) j++;
                j--;
            }
            int curI = i;
            while(i < n and arr[curI] == arr[i]) i++;
            i--;
        }
        return ans;
    }
};