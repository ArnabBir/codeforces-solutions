#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>
using namespace std;

int main() {

	fastIO;
	int t, n;
	ll s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		vector<pii> range(n);
		for(int i = 0; i < n; ++i)	cin>>range[i].first>>range[i].second;
		int l = 1, r = INT_MAX;
		sort(range.begin(), range.end());
		while(l+1 < r) {
			int m = l + (r-l)/2;
			int count = 0;
			ll sumSalary = 0;
			vector<int> index;
			for(int i = 0; i < n; ++i) {
				if(range[i].second < m) {
					sumSalary += (ll)range[i].first;
				}
				else if(m <= range[i].first) {
					++count;
					sumSalary += (ll)range[i].first;
				}
				else {
					index.push_back(range[i].first);
				}
			}
			int remaining = max(0, (n+1)/2 - count);
			if(index.size() < remaining) {
				r = m;
				continue;
			}
			for(int x = 0; x < index.size(); ++x) {
				if(x < index.size() - remaining) {
					sumSalary += (ll) index[x];
				}
				else {
					sumSalary += m;
				}
			}
			if(sumSalary > s) {
				r = m;
			}
			else {
				l = m;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}
