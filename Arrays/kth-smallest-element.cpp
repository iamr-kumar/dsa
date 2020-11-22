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

// Using Max Heaps
// Steps: 1. Build a max heap of the first k elements of the array. TC - O(k)
// 2. For the rest of the elements, compare them with the root of the heap.
// 3. If it is smaller than root, then make it root and call heapify for MH.
// 4. ELse, ignore it
// 5. After these steps, the root is the required element

class MaxHeap {
    int* harr;
    int capacity;
    int heapSize;
    public:
    MaxHeap(int arr[], int size) {
        harr = arr;
        heapSize = size;
        int i = (heapSize - 1) / 2;
        while(i >= 0) {
            maxHeapify(i);
            i++;
        }
    }
    void maxHeapify(int i);
    int parentNode(int i) { return (i - 1) / 2; }
    int leftNode(int i) { return 2 * i + 1; }
    int rightNode(int i) { return 2 * i + 2; }
    int extractMax();
    int getMax() { return harr[0]; }
    void replaceMax(int x) {
        harr[0] = x;
        maxHeapify(0);
    }

};

// To heapify a max heap rooted at index i, assuming that subtress are already heapified.
void MaxHeap::maxHeapify(int i) {
    int left = leftNode(i);
    int right = rightNode(i);
    int largest = i;
    if(left < heapSize and harr[left] > harr[largest]) largest = left;
    if(right < heapSize and harr[right] > harr[largest]) largest = right;
    if(largest != i) {
        swap(harr[largest], harr[i]);
        maxHeapify(largest);
    }
}

int solveByMaxHeap(int arr[], int n, int k) {
    // Build a heap for the first k elements
    MaxHeap newHeap(arr, k);

    // For the rest of the elements, compare with the root of the heap.
    for(int i = k; i < n; ++i) {
        if(arr[i] < newHeap.getMax())
            newHeap.replaceMax(arr[i]);
    }

    cout << newHeap.getMax() << "\n";

}

// Quick Select method
// Optimization over the sorting method if quick sort is used as the sorting algorithm
// Not to complete quick sort, but stop when the pivot element is the kth smallest element
// Not recurr for both sides, but recur depeneding on the position of the pivot.
// TC - O(n^2) in worst case but O(n) in average
int solveByQuickSelect(int arr[], int l, int r, int k) {
    if(k > 0 and k <= r - l + 1) {
        // Partition the array around the pivot by choosing the last element as the pivot
        int pos = partition(arr, l, r);
        if(pos - l == k - 1) {
            return arr[pos];
        }
        else if(pos - l > k - 1) {
            return solveByQuickSelect(arr, l, pos - 1, k);
        }
        else {
            return solveByQuickSelect(arr, pos + 1, r, k - pos + l - 1);
        }
    }

    return INT_MAX;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l - 1;
    for(int j = l; j <= r - 1; j++) {
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i;
}

// Slightly optimized version of quick select, by choosing a pivot randomly.
// Steps: 1. Generate a random index between l and r, swap it with the last element
// 2. Implement standard partition
int betterQuickSelect(int arr[], int l, int r, int k) {
    if(k > 0 and k <= r - l + 1) {
        int pos = randomPartition(arr, l, r);

        if(pos - l == k - 1) {
            return arr[pos];
        }
        else if(pos - l > k - 1) {
            // Recur for left subarray
            return betterQuickSelect(arr, l, pos - 1, k);
        }
        else {
            // Recurr for the right subarray
            return betterQuickSelect(arr, pos + 1, r, k - pos + l - 1);
        }
    }
    return INT_MAX;
}

int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l , r);
}

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    solveBySort(arr, n, k);
    solveByMinHeap(arr, n, k);
    solveByMaxHeap(arr, n, k);
    solveByQuickSelect(arr, 0, n - 1, k);
    betterQuickSelect(arr, 0, n - 1, k);
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