#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define ll long long int
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first;
}

int main() {
    
    fastIO;
    int q, c, m, x;
    cin>>q;
    while(q--) {
        cin>>c>>m>>x;
        int result  = 0;
        if(x >= c && x >= m) {
            result = min(c, m);
        }
        else if(x >= c && x <= m) {
            result = c;
        }
        else if(x <= c && x >= m) {
            result = m;
        }
        else {
            c -= x;
            m -= x;
            result = x + min((c+m)/3, min(c, m)); 
        }
        cout<<result<<endl;
    }
    return 0;
}
