#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define N 2048
#define ll long long int
using namespace std;

int main() {

	fastIO;
	int q, n, x;
	cin>>q;
	while(q--) {
		bool win = false;
		cin>>n;
		map<int, int>	m;
		for(int i = 0; i < n; ++i) {
			cin>>x;
			++m[x];
		}
		for(auto & pair : m) {
		    //cout<<pair.first<<" -> "<<pair.second<<endl;
			if(pair.first == N) {
				win = true;
				break;
			}
			if(pair.second > 1) {
			    m[2*pair.first] += (pair.second / 2);
			    m[pair.first] = pair.second % 2;
			}
		}
		cout<<(win ? "YES" : "NO")<<endl;
	}
	return 0;
}2048 Game
