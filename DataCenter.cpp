#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
using namespace std;

int main() {
    
    fastIO;
	int n;
	cin>>n;
	int rootn = sqrt(n);
	int i;
	for(i = rootn; i >=1; --i) {
		if((i * (n/i)) == n) {
			break;
		}
	}
	cout<<2*(i+n/i)<<endl;
	return 0;
}
