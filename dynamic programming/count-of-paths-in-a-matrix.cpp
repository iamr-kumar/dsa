// Solved on GFG

#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    long long count[n][m];
    for(int i = 0; i < n; ++i) {
        count[i][0] = 1;
    }
    for(int i = 0; i < m; ++i) {
        count[0][i] = 1;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            count[i][j] = (count[i - 1][j] % MOD + count[i][j - 1] % MOD) % MOD;
            // cout << count[i][j] << " ";
        }
        // cout << endl;
    }
    long long ans = count[n - 1][m - 1];
    cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
        solve();
    
    }
	
	return 0;
}