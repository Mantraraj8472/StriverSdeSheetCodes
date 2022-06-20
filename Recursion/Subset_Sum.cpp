// problem link:
// https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&leftPanelTab=0

void solve(int ind, vector<int> &num, int sum, vector<int> &ans){
    if(ind == 0) {
        ans.push_back(sum);
        return;
    }
    solve(ind - 1, num, sum, ans);
    solve(ind - 1, num, sum + num[ind - 1], ans);
}

vector<int> subsetSum(vector<int> &num)
{
//     vector<int> ans;
//     int sum = 0;
//     solve(num.size(), num, sum, ans);
//     sort(ans.begin(), ans.end());
//     return ans;
    
    // Iterative way
    vector<int> ans;
    int n = num.size();
    for(int i = 0; i < (1 << n); i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if((1 << j) & i) 
                sum += num[j];
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}