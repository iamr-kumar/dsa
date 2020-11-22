// Probelm: Rearrange positive and negative numbers with constant extra space. The order of appearance should be maintained.

#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; ++i) cout << arr[i] <<" ";
    cout << "\n";
}

// Modified insertion sort method
// If the current element is positive(arr[i]), do nothing
// If the current element is negative, insert it before the first positive element in the array arr[0... i - 1]
// TC - O(n^2), SC - O(1)
void solveByInsertion(int arr[], int n) {
    int key;
    for(int i = 0; i < n; ++i) {
        key = arr[i];
        if(key > 0 ) continue;
        int j = i - 1;
        while(j >= 0 and arr[j] > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
}

// Merge Sort Method
// Modify the merging to first select negative elements from both the array
// TC -O(nlogn) SC - Uses O(n) extra space - not allowed
void mergeSimple(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    // Copy data to temp arrays
    for(int i = 0; i < n1; ++i) L[i] = arr[i + l]; 
    for(int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 and L[i] < 0) {
        arr[k++] = L[i++];
    } 
    while(j < n2 and R[j] < 0) arr[k++] = R[j++];
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void reverse(int arr[], int l, int r) {
    while(l < r) {
        swap(arr[l], arr[r]);
        l++;
        r++;
    }
}

// Modified merge to not use temp array while merging
// Reverse positive half of left sub array and negative half of right subarray
// Reverse the resulant range
void mergeModified(int arr[], int l, int m, int r) {
    int i = l, j = m + 1;   //Starting indexes of the two subarrays
    while(i <= m and arr[i] < 0) i++;
    // arr[i...m] is positive
    while(j <= r and arr[j] < 0) j++;
    // arr[j...r] is positive
    // Reverse positive part of left subarray
    reverse(arr, i, m);
    // Reverse negative part of rigth subarray
    reverse(arr, m + 1, j - 1);
    // Reverse arr[i...j-1]
    reverse(arr, i, j - 1);
}

void solveByMergeSimple(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        solveByMergeSimple(arr, l, m);
        solveByMergeSimple(arr, m + 1, r);

        mergeModified(arr, l, m, r);
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < 0; ++i) cin >> arr[i];

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
    return(0);
}