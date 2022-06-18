// problem link:
// https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_975277?topList=striver-sde-sheet-problems&leftPanelTab=0

int findMinimumCoins(int amount) 
{
    vector<int> currency = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ind = 0;
    int ans = 0;
    while(amount > 0){
        if(currency[ind] <= amount){
            ans += amount / currency[ind];
            amount -= amount / currency[ind] * currency[ind];
        }
        else ind++;
    }
    return ans;
}
