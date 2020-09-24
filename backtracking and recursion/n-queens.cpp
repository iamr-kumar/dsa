// Solved on Geeks for geeks practice

#include<bits/stdc++.h>

using namespace std;

void printSol(int arr[10][10], int n) {
    cout << "[";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(arr[i][j] == 1) {
                cout << (j + 1) << " ";
            }
        }
    }
    
    cout << "] ";
}

bool isSafe(int arr[10][10], int n, int col, int row) {
    for(int i = 0; i < col; ++i) {
        if(arr[row][i])
            return false;
    }
    
    for(int i = 0, j = 0; i <= row, j <= col; i++, j++) {
        if(arr[i][j])
            return false;
    }
    
    for(int i = n - 1, j = 0; i >= row, j <= col; i--, j++) {
        if(arr[i][j])
            return false;
    }
    
    return true;
}

bool nQueen(int arr[10][10], int n, int col) {
    if(col == n) {
        printSol(arr, n);
        return true;
    }
    
    bool res = false;
    
    for(int i = 0; i < n; ++i) {
        if(isSafe(arr, n, col, i)) {
            arr[i][col] = 1;
            res = nQueen(arr, n, col + 1) or res;
            arr[i][col] = 0;
            
        }
    }
    
    return res;
}

void solve(){
    int n;
    cin >> n;
    int board[10][10];
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) 
            board[i][j] = 0;
    if(nQueen(board, n, 0) == 0) {
        cout << -1 << "\n";
        return;
    }
    cout << "\n";
    
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