// Problem Statement - Given an array, cyclically rotate an array by one.
#include<bits/stdc++.h>

using namespace std;

// Simple solution - keep two variables as temp to keep track of previous and current elements
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    if(n == 1) {
        cout << arr[0] << "\n";
        return;
    }
    int prev = arr[0], curr;
    for(int i = 1; i <= n - 1; ++i) {
        curr = arr[i];
        arr[i] = prev;
        prev = curr;
    }
    arr[0] = curr;
    for(int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}