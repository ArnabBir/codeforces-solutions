#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>
using namespace std;

bool checkStrings(string a, string b, int n) {
	if(a.size() != b.size()) return false;
	int countA[26], countB[26];
	memset(countA, 0, sizeof countA);
	memset(countB, 0, sizeof countB);
	for(int i = 0; i < n; ++i) {
		++countA[(int)(a[i]-'a')];
		++countB[(int)(b[i]-'a')];
	}
	for(int i = 0; i < 26; ++i) {
		if(countA[i] != countB[i]) return false;
	}
	for(int i = 0; i < 26; ++i) {
		if(countA[i] > 1)	return true;
	}
	int invA = 0, invB = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			if(a[i] > a[j])	++invA;
			if(b[i] > b[j])	++invB;
		}
	}
	return ((int)abs(invA - invB) % 2) == 0;
}

int main() {

	fastIO;
	int q, n;
	string a, b;
	cin>>q;
	while(q--) {
		cin>>n>>a>>b;
		cout<<(checkStrings(a, b, n) ? "YES" : "NO")<<endl;
	}
	return 0;
}
