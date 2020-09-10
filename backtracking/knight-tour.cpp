#include<bits/stdc++.h>
#define N 8

using namespace std;

int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int sol[N][N];

bool isSafe(int x, int y) {
    return (x >= 0 and y >= 0 and x < N and y < N and sol[x][y] == -1);
}

int solveKnightTour(int x, int y, int moves) {
    if(moves == N * N) 
        return 1;
    int next_x, next_y;
    for(int k = 0; k < 8; ++k) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x, next_y)) {
            sol[next_x][next_y] = moves;
            if(solveKnightTour(next_x, next_y, moves + 1))
                return 1;
            else 
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int main() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            sol[i][j] = -1;
        }
    }
    
    // starting from first cell
    sol[0][0] = 0;
    if(solveKnightTour(0, 0, 1) == 0) {
        cout << "NO SOLUTION!";
    } 
    else {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }

}