#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n[3];
	int t;
	long long int result = 0;
	cin>>n[0]>>n[1]>>n[2];
	vector<vector<int>> v(3);
	v[0] = vector<int>(n[0]);
	v[1] = vector<int>(n[1]);
	v[2] = vector<int>(n[2]);
 
	for(int j = 0; j < 3; ++j) {
		for(int i = 0; i < n[j]; ++i) {
			cin>>t;
			v[j][i] = t;
		}
	}
	for(int i = 0; i < 3; ++i) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	
	long long int dp[n[0]+1][n[1]+1][n[2]+1];
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < n[0]+1; ++i) {
		for(int j = 0; j < n[1]+1; ++j) {
			for(int k = 0; k < n[2]+1; ++k) {
				if(i < n[0] && j < n[1]) {
					dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + v[0][i] * v[1][j]);
				}
				if(j < n[1] && k < n[2]) {
					dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + v[1][j] * v[2][k]);
				}
				if(i < n[0] && k < n[2]) {
					dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + v[0][i] * v[2][k]);
				}
				result = max(result, dp[i][j][k]);
			}
		}
	}
	cout<<result<<endl;
	return 0;
}
