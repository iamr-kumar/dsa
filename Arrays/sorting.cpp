#include<bits/stdc++.h>

using namespace std;

// Bubble sort - swap adjacent elements if in wrong order
// TC - O(n^2) in worst case
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection sort - repeatedly find the minimum element from the unsorted array and put it at the beginning.
// TC - O(n^2) in worst case
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion sort - Compare each element to its predecessor. If smaller, inert it into its right place
// TC - O(n^2)
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge sort - Divide and Conquer method
// Divide the array into two halves, sort each of them and then merge
// TC - O(nlogn)
void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for(int j = 0; j < n2; ++j) R[j] = arr[m + l + j];

    // Merge the arrays back to arr[]
    int i = 0, j = 0, k = l;
    while(i < n1 and j < n2) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick Sort - Divide and Conquer, based on partitioning and placing other elements around it.
// Pick a pivot (here, the last element) and place it at its right position in the sorted array
// Place the elements smaller than pivot on its left, and the elements greater than pivot to its right
// TC - O(nlogn), O(n^2) in worst case
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Returns the partitioning index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; ++j) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

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