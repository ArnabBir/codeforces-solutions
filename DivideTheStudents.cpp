#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
using namespace std;

int main() {
	
	fastIO;
	int t, a, b, c, x;
	cin>>t;
	while(t--) {
		cin>>a>>c>>b;
		if(a < b)	swap(a, b);
		int l, r, m, h;
		x = max(a, c);
		l = min(b, c); r = max(a, c);
		while(l < r) {
			m = (int)((l+r)/2.0);
			if(2*m < a || m < b || 3*m < a+b+c) {
				l = m+1;
			}
			else {
				x = m;
				r = m;
			}
		}
		cout<<x<<endl;		
	}
	return 0;
}
