#include<bits/stdc++.h>
#define N 8

using namespace std;

int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int sol[N][N];

// To check if a cell is valid or not
bool isValid(int x, int y) {
    return (x >= 0 and y >= 0 and x < N and y < N and sol[x][y] == -1);
}

int getDegree(int x, int y) {
    int count = 0;
    // check for all 8 adjacent possibilities
    for(int i = 0; i < N; ++i) {
        if(isValid(x + xMove[i], y + yMove[i]))
            count++;
    }

    return count;
}

// Get next move based on the minimum degree
bool getNextMove(int *x, int *y) {
    int minDegInd = -1, c, minDeg = N + 1;
    int next_x, next_y;

    // Try all 8 adjacent starting from a random adjacent.
    int start = rand() % N;
    for(int i = 0; i < N; ++i) {
        int k = (start + i) % N;
        next_x = *x + xMove[k];
        next_y = *y + yMove[k];
        // Check if this cell is valid or not
        if(isValid(next_x, next_y) and (c = getDegree(next_x, next_y) < minDeg)) {
            minDegInd = k;
            minDeg = c;
        }
    }

    if(minDegInd == -1)
        return false;

    // Update current cell
    next_x = *x + xMove[minDegInd];
    next_y = *y + yMove[minDegInd];

    // Mark next move
    sol[next_x][next_y] = a[*x][*y] + 1;

    *x = next_x;
    *y = next_y;

    return true;
}
// Get neighbours... If one knight move away from beginning, tour is close
bool neighbour(int x, int y, int start_x, int start_y) {
    for(int i = 0; i < N; ++i) {
        if(x + xMove[i] == start_x and y + yMove[i] == start_y)
            return true;
    }

    return false;
}

bool findClosedTour() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            sol[i][j] = -1;
        }
    }
    // Pick a random starting cell
    int start_x = rand() % N;
    int start_y = rand() % N;

    int x = start_x, y = start_y;
    sol[x][y] = 1;

    // Keep picking the next points
    for(int i = 0; i < N * N - 1; ++i) {
        if(getNextMove(&x, &y) == 0)
            return false;
    }

    if(!neighbour(x, y, start_x, start_y))
        return false;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << sol[i][j] << " "; 
        }
        cout << "\n";
    }

    return true;
}

int main() {


    while(!findClosedTour()) {
        ;
    }

    return 0;

}