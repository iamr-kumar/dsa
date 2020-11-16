// Problem Statement
// Find the minimum and maximum element in an array with minimum possible comparisons.

#include<bits/stdc++.h>

using namespace std;

// Simple approach - Linear Search, comparing each element
// Total comparisons : 1 + 2 (n - 2) in worst case and 1 + n - 2 in the best case
pair<int, int> linearSearch(int arr[], int n) {
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < n; ++i) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    pair<int, int> answer;
    answer = make_pair(min, max);
    return answer;
}

// Tournament Method - Divide the array into two parts and compare the minimum and mximum of both parts
// Total comparisons - 3n /2 - 2 if n is power of 2, and more than this if n is not a power of 2.
pair<int, int> getMinMax(int arr[], int low, int high) {
    pair<int, int> minmax, mml, mmr;
    int mid;
    if(low == high) {
        minmax = make_pair(arr[low], arr[low]);
        return minmax;
    }
    if(high == low + 1) {
        minmax = make_pair(arr[low], arr[high]);
        return minmax;
    }
    mid = (high + low) / 2;
    mml = getMinMax(arr, low, mid);   // Find the min, max pair for the left half of the array
    mmr = getMinMax(arr, mid + 1, high);   // Find the min, max pair for the right hand of the array.
    // Compare the minimum of the two halves
    if(mml.first < mmr.first) {
        minmax.first = mml.first;
    }
    else {
        minmax.first = mmr.first;
    }
    // Compare the maximum of the two halves
    if(mmr.second > mml.second) {
        minmax.second = mmr.second;
    }
    else {
        minmax.second = mml.second;
    }
    return minmax;

}

// Compare in Pairs
// If n is odd, initialize min and max to the first element of the array. If n is even, 
// initialize min and max to the minimum and maximum of the first two elements of the array respectively.
// If n is odd, 3 *  (n - 1) / 2 comparisons in total
// If n is even, 1 initial comparisons + 3 * ( n - 2) / 2 comparisons = 3n/2 + 2 comparisons in total
// This method is best among the three
pair<int, int> pairGetMinMax(int arr[], int n) {
    int minimum, maximum, i;
    if(n & 1) {
        minimum = arr[0];
        maximum = arr[0];
        i = 1;
    }
    else {
        minimum = min(arr[0], arr[1]);
        maximum = max(arr[0], arr[1]);
        i = 2;
    }
    while(i < n - 1) {
        maximum = max(maximum, max(arr[i], arr[i + 1]));
        minimum = min(minimum, min(arr[i], arr[i + 1]));
        i += 2;
    }
    return make_pair(minimum, maximum);

}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    pair<int, int> answer1 = linearSearch(arr, n);
    cout << answer1.first << " " << answer1.second << "\n";
    pair<int, int> answer2 = getMinMax(arr, 0, n - 1);
    cout << answer2.first << " " << answer2.second << "\n";
    pair<int, int> answer3 = pairGetMinMax(arr, n);
    cout << answer3.first << " " << answer3.second << "\n";

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

