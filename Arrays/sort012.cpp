#include<bits/stdc++.h>

using namespace std;

// Given an array of size N containing 0s, 1s, and 2s; sort the array in ascending order.
// without using a sorting algorithm

// Simple approach - Count the number of 0s, 1s, and 2s and fill the array accordingle in sorted manner
void sort012Simple(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    int k = 0;
    for(int i = 0; i < count0; ++i, ++k) arr[k] = 0; 
    for(int i = 0; i < count1; ++i, ++k) arr[k] = 1; 
    for(int i = 0; i < count2; ++i, ++k) arr[k] = 2;
    for(int i = 0; i < n; ++i) cout << arr[i] << " "; 
    cout << "\n";

}

// Doing in a single paas - Dutch national flag algorithm - three way partitioning
// Array is divided into four parts - 
// 1. a[1...low - 1] - 0s
// 2. a[low... mid - 1] - 1s
// 3. a[mid... high] - unknown
// 4. a[high + 1] - 2s

// Algo - maintain low = 0, mid = 0, high = n - 1
// if arr[mid] == 0, swap(arr[low], arr[mid]) low++ mid++
// if arr[mid] == 1, mid++
// if arr[mid] == 2, swap(arr[mid], arr[high]) high--

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++; mid++;
        } 
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    for(int i = 0; i < n; ++i) cout << arr[i] << "\n";
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort012Simple(arr, n);
    sort012(arr, n);

}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }


}

