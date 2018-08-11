#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

//long long dp[100001][100001] = {0};


long long P(int n, int r) {
    
    if(n == 0)  return 0;
    if(n == 1)  return 1;
    if(n < r)   return 0;
    
    long long prod = 1;
    for(int i = n; i > n-r; --i) {
            prod = (prod * i) % MOD;
    }
	return prod;
}

int main() {

	ios::sync_with_stdio(false);
	long long comb;
	int n, m, q, l, r, k;
	cin>>n>>m>>q;
	vector<int> v(n);
	unordered_map<int, int>	um, um_;
	for(int i = 0; i < n; ++i){
		cin>>v[i];
		++um[v[i]];
	}
	while(q--) {
		cin>>l>>r>>k;
		comb = 1;
		um_ = um;
		for(int i = l; i <= r; ++i) {
			comb = (comb * (um_[v[i-1]] + k)) % MOD;
			--um_[v[i-1]];
		}
		comb = (comb * P(n + m*k - (r-l+1), n-(r-l+1))) % MOD;
		cout<<comb<<endl;
	}

	return 0;
}
