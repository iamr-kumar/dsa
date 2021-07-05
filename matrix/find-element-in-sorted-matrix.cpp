#include<bits/stdc++.h>

using namespace std;

bool binarySearch(int arr[][100], int i, int low, int high, int x) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[i][mid] == x) {
            return true;
        } else if(arr[i][mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

bool binarySearchOnColumn(int arr[][100], int r, int c, int x) {
    if(r == 1) {
        return binarySearch(arr, 0, 0, c - 1, x);

    }
    int col = c / 2;
    int low = 0, high = r - 1;
    while(low + 1 < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid][col] == x) {
            return true;
        }
        else if(arr[mid][col] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if(arr[low][col] == x or arr[low + 1][col] == x) return true;
    // look in the four halfs 
    if(arr[low][col - 1] >= x) return binarySearch(arr, low, 0, col - 1, x);
    if(arr[low][c - 1] >= x) return binarySearch(arr, low, col + 1, c - 1, x);
    if(arr[low + 1][col - 1] <= x) return binarySearch(arr, low + 1, 0, col - 1, x);
    if(arr[low + 1][c- 1] <= x) return binarySearch(arr, col + 1, 0, c - 1, x);
}