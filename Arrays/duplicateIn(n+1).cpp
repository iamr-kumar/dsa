// Problem Statement - Find the duplicate element in an array of size n + 1 containing elements from [1...n] inclusive
#include<bits/stdc++.h>

using namespace std;

// Simple method - Sort the array -> the duplicate elements will be adjacent to each other
// TC - O(nlogn) SC - O(1)
void solveSimple(int arr[], int n) {
    sort(arr, arr + n + 1);
    // Traverse the array to look for adjacent equal elements
    for(int i = 0; i < n; ++i) {
        if(arr[i] == arr[i + 1]) {
            cout << arr[i] << "\n";
            return;
        }
    }
}

// Hash Map method - create a hash map for the given array.
// The element which has collision is the duplicate element.
// TC - O(n) SC - O(n)
void solveHash(int arr[], int n) {
    int hash[n];
    memset(hash, 0, sizeof(hash));
    for(int i = 0; i < n + 1; ++i) {
        if(hash[arr[i]] == 0) hash[arr[i]]++;
        else {
            cout << arr[i] << "\n";
            break;
        }
    }
}

// Linked List cycle method using Tortoise algorithm
// As there is a duplicate element, a cycle will be formed while traversing through all the elements
// Create a cycle like arr[i] -> arr[arr[i]] -> arr[arr[arr[i]]] ...
// Take two pointers - slow and fast. Intitalize both as the first element of the cycle.
// Move the fast pointer two at a time, and slow pointer one at a time until they collide
// After the first collision -> initalize fast again to the first element
// Move both the pointers one at time.
// The element on which they collide for the second time will be the duplicate element
void solveByCycle(int arr[], int n) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];  // Move by one
        fast = arr[arr[fast]];  // Move by two
    } while(slow != fast);

    // Set fast back to the first element
    fast = arr[0];
    while(slow != fast) {
        // Move both by one
        slow = arr[slow];
        fast = arr[fast]; 
    }
    cout << slow << "\n";
}


void solve() {
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 0; i < n + 1; ++i) arr[i];
    solveSimple(arr, n);
    solveHash(arr, n);
    solveByCycle(arr, n);

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