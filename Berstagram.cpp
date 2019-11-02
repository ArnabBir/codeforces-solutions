#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
using namespace std;


int main() {

	fastIO;
	int n, m, vote;
	cin>>n>>m;
	vector<int> pinv(n);
	vector<int> a(n);
	vector<int> b(n);
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		a[i] = b[i] = p[i] = pinv[i] = i;
	}
	for(int i = 0; i < m; ++i)	{
		cin>>vote;
		--vote;
		if(p[vote] > 0) {
			int px = vote, py = pinv[p[vote]-1];
			swap(pinv[p[vote]], pinv[p[vote]-1]);
			--p[px];
			++p[py];
			a[px] = min(a[px], p[px]);
			b[py] = max(b[py], p[py]);

		}
	}
	for(int i = 0; i < n; ++i) {
		cout<<a[i]+1<<" "<<b[i]+1<<endl;
	}
	return 0;
}
