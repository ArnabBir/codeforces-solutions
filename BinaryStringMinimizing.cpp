#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>
using namespace std;

int main() {
	fastIO;
	int q, n;
	ll k;
	string s;
	cin>>q;
	while(q--) {
		cin>>n>>k>>s;
		priority_queue<int, vector<int>, greater<int>> zeros, ones;
		bool found1 = false;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '0') {
				zeros.push(i);
			}
			else {
				ones.push(i);
			}
		}
		int x = 0, y = 0;
		while(k > 0 && !zeros.empty() && !ones.empty()) {
			x = zeros.top(); y = ones.top();
			if(x > y && x - y <= k) {
				k -= x - y;
				//cout<<x<<" "<<y<<endl;
				swap(s[x], s[y]);
				ones.pop();
				zeros.pop();
				ones.push(x);
				zeros.push(y);
				
			}
			else if(zeros.top() < ones.top()) {
				zeros.pop();
			}
			else {
				ones.pop();
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
