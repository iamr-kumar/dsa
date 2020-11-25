// Problem Statement - Merge two sorted arrays in O(1) extra space

#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

// Insertion sort method:
// Compare the last element of the first array and first element of the second array
// If the last element is bigger, swap them.
// Insert both the elements at their correct positions in the respective arrays
// TC - O(m * n) SC - O(1)
void insertFromEnd(int arr[], int size) {
    int key = arr[size - 1], i = size - 2;
    while(key < arr[i] and i >= 0) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
    
}

void insertFromBeg(int arr[], int size) {
    int key = arr[0], i = 1;
    while(key > arr[i] and i < size) {
        arr[i - 1] = arr[i];
        i++;
    }
    arr[i - 1] = key;
}

void solveByInsertion(int arr1[], int arr2[], int n, int m) {
    while (arr1[n - 1] > arr2[0]) {
        swap(arr1[n - 1], arr2[0]);
        insertFromEnd(arr1, n);
        insertFromBeg(arr2, m);
        
    }
}


// Gap method - Compare elements which are far from each other
// Calculate the initial gap as ceil(m + n) / 2, then keep dividing it by 2
// Compare the two elements having an interval equal to the value of gap
// When the gap becomes 0, the two arrays are merged
// TC - O((n + m)*log(n + m)) SC - O(1)
void solveByGap(int arr1[], int arr2[], int n, int m) {
    int gap = ((m + n) / 2) + ((m + n) % 2);
    while(gap > 0) {
        int i = 0, j = 0;
        for(i = 0; i + gap < n; ++i) {
            if(arr1[i] > arr1[i + gap]) {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        for(j = gap > n ? gap - n : 0; j < m and i < n; ++j, ++i) {
            if(arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
        }
        if(j < m) {
            for(j = 0; j + gap < m; ++j) {
                if(arr2[j] > arr2[j + gap]) {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
            
        }
        if(gap <= 1) break;
        gap = (gap / 2) + gap % 2;
    }
    printArray(arr1, n);
    printArray(arr2, m);
}


void solve() {
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];
    solveByInsertion(arr1, arr2, n, m);
    solveByGap(arr1, arr2, n, m);
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