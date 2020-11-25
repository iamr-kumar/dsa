// Problem Statement - Find the maximum contigous subarray sum

#include <bits/stdc++.h>

using namespace std;

// Simple method - Run three loops and check for every possible subarray
// TC - O(n^3) SC - O(1)
void solveSimple(int arr[], int n) {
    int maxSum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int sum = 0;
            for(int k = i; k < j and j >= i; ++k) {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << "\n";
}

// Simple optimization - remove the third loop
// TC - O(n^2) SC - O(1)
void solveInTwoLoop(int arr[], int n) {
    int maxSum = 0;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = i; j < n; ++j) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << "\n";
}

// Kadane's Algorithm
// Intialize the sumSoFar as 0
// Traverse the array and add elements to sumSoFar
// If sumSoFar > maxSum, maxSum = sumSoFar
// If sumSoFar < 0, sumSoFar = 0
// If all elements are negative, the largest element will be the answer
// TC - O(n) SC - O(1)
void solveByKadane(int arr[], int n) {
    int sumSoFar = 0;
    int maxSum = INT_MIN;
    int maxElement = INT_MIN;
    for(int i = 0; i < n; ++i) {
        sumSoFar = max(sumSoFar + arr[i], 0);
        maxSum = max(maxSum, sumSoFar);
        maxElement = max(maxElement, arr[i]);
    }
    maxSum = maxSum <= 0 ? maxElement : maxSum;
    cout << maxSum << "\n";
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    solveSimple(arr, n);
    solveInTwoLoop(arr, n);
    solveByKadane(arr, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}