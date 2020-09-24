#include<bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& matrix, int row, int col, int m, int n, int p, vector<int>& path) {
    // Reached the bottom row of the matrix - can only go right
    if(row == m - 1) {
        for(int j = col; j < n; ++j) {
            path[p + j - col] = matrix[row][j];
        }
        for(int i = 0; i < p + n - col; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    // Reached the rightmost column - can only go down
    if(col == n - 1) {
        for(int j = row; j < m; ++j) {
            path[p + j - row] = matrix[j][col];
        }
        for(int i = 0; i < p + m - row; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    // Add the current cell to path
    path[p] = matrix[row][col];
    // Recurr for right
    solve(matrix, row + 1, col, m, n, p + 1, path);
    // Recur for left
    solve(matrix, row, col + 1, m, n, p + 1, path);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<int> path(m + n);
    solve(matrix, 0, 0, m, n, 0, path);
}