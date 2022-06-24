#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

vector<ll> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    vector<ll> pre(n + 1, 0ll);
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i - 1] + arr[i - 1]) % mod;
    }
    vector<ll> ans;
    for(int i = 0; i < q; i++){
        ll l = queries[i][0], r = queries[i][1];
        ll noEle = r - l + 1;
        ll wholeSum = (noEle / n);
        if(noEle % n == 0)
            wholeSum = (wholeSum - 1 + mod) % mod;
        l %= n;
        r %= n;
        if(l == 0)
            l = n;
        if(r == 0) 
            r = n;
        ll var; 
        if(r >= l)
            var = ((((pre[n] * (wholeSum % mod)) % mod) + ((pre[r] - pre[l-1] + mod) % mod)) % mod);
        else
            var = ((((pre[n] * (wholeSum % mod)) % mod) + ((((pre[n] - pre[l-1] + mod) % mod) + pre[r] + mod) % mod)) % mod);
        ans.push_back(var);
    }
    return ans;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin >>v[i];
		int q;cin>>q;
		vector<vector<ll>> queries(q);
		for(int i=0;i<q;i++){
			ll l;cin>>l;
			queries[i].push_back(l);
		}
		for(int i=0;i<q;i++){
			ll r;cin>>r;
			queries[i].push_back(r);
		}
		vector<ll> ans;
		ans=sumInRanges(v, n, queries, q);
		for(int i=0;i<q;i++) cout<<ans[i]<<' ';
		cout<<endl;
	}
}