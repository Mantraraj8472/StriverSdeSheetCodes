// problem link:
// https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331?topList=striver-sde-sheet-problems&leftPanelTab=0

void solve(int ind, vector<int> &arr, vector<int> &temp, int sum, vector<vector<int>> &ans, int k){
    if(sum == k and temp.size() and ind == arr.size() + 1){
        ans.push_back(temp);
    }
    if(ind == arr.size() + 1) return;
    solve(ind + 1, arr, temp, sum, ans, k);
    temp.push_back(arr[ind - 1]);
    solve(ind + 1, arr, temp, sum + arr[ind - 1], ans, k);
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    solve(1, arr, temp, sum, ans, k);
    return ans;
}