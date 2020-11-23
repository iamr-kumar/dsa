// Problem: Move all negative numbers to the beginnig and positive to the end with constant extra space

#include<bits/stdc++.h>

using namespace std;

// Two Pointer Method:
// 1. Keep left = 0 and right = n - 1
// 2. If arr[left] < 0 and arr[right] > 0 => left++, right--
// 3. If arr[left] > 0 and arr[right] < 0 => swap(arr[left], arr[right]), left++, right--
// 4. If arr[left] < 0 and arr[right] < 0 => left++
// 5. If arr[left] > 0 and arr[right] > 0 => right--
// TC - O(n), SC-O(1)
void solveByTwoPointer(int arr[], int n) {
    int left = 0, right = n - 1;
    while(left < right) {
        if(arr[left] > 0 and arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if(arr[left] < 0 and arr[right] < 0) {
            left++;
        }
        else if(arr[left] < 0 and arr[right] > 0) {
            left++;
            right--;
        }
        else if(arr[left] > 0 and arr[right] > 0) {
            right--;
        }
    }
    for(int i = 0; i < n; ++i) cout << arr[i] <<" ";
    cout << "\n";
}

// Quick Sort Partition method
// 1. Partition the array with 0 as the pivot
// 2. Place all elements less than 0 to the left and elements more than 0 to the right
// TC - O(n), SC-O(1)
void solveByPartition(int arr[], int n) {
    int j = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    solveByTwoPointer(arr, n);
    solveByPartition(arr, n);

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