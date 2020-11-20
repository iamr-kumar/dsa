// Problem Statement - Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct.

#include<bits/stdc++.h>

using namespace std;



// Simple Solution - Sorting 
// TC - O(nlogn)
int solveBySort(int arr[], int n, int k) {
    sort(arr, arr + n); 
    cout << arr[k - 1 ] << "\n";
}

// Using Heaps:
// Min-Heap - Create a min-heap and call extract min k times.
// extract min extracts the root(minimum) element from the heap
// Steps - 1. build a min heap from the input array
// 2. 

class MinHeap {
    int* harr;
    int capacity;
    int heapSize;
    public:
    MinHeap(int a[], int size);
    void MinHeapify(int i); // TO heapify a subtree rooted at index i
    int parent(int i) { return (i - 1) / 2; }  // Returns the parent of a node at index i
    int returnLeft(int i) { return 2 * i + 1; } //Return the left child of a node at index i
    int returnRight(int i) { return 2 * i + 2; } //Returns the right child of a node at index i
    int extractMin();  //To extract the root (minimum) element
    int getMin() { return harr[0]; } //Return minimum element
};

MinHeap::MinHeap(int a[], int size) {
    heapSize = size;
    harr = a;
    int i = (heapSize - 1) / 2;
    while(i >=  0) {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i) {
    int l = returnLeft(i);   //Get the left child index
    int r = returnRight(i);   //Get the right child index
    int smallest = i;      
    if(l < heapSize and harr[l] < harr[smallest]) {   // If left child is smaller than root, set smallest index to left child
        smallest = l;
    }
    if(r < heapSize and harr[r] < harr[smallest]) {   // If right child is smaller than root, set smallest index to right child
        smallest = i;
    }
    if(smallest != i) {                               // If parent is not the smallest element, swap with the correct child.
        swap(harr[i], harr[smallest]);                // Heapify the swapped child again.
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if(heapSize == 0)
        return INT_MAX;
    int root = harr[0];
    // if there are more than 1 items, move the last item to root and call heapify.
    if(heapSize > 1) {
        harr[0] = harr[heapSize - 1];
        MinHeapify(0);
    }
    heapSize--;
    return root;
}

int solveByMinHeap(int arr[], int n, int k) {
    MinHeap newMinHeap(arr, n);

    // Extract min k - 1 times
    for(int i = 0; i < k - 1; ++i) {
        newMinHeap.extractMin();
    }
    cout << newMinHeap.extractMin() << "\n";
}

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    solveBySort(arr, n, k);
    solveByMinHeap(arr, n, k);

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