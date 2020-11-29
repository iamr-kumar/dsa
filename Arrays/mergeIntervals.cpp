// Problem Statement - Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers for simplicity. 

#include<bits/stdc++.h>

using namespace std;

void printAnswer(vector<pair<int, int>> &intervals) {
    cout << '[';
    for(auto x: intervals) {
        cout << '[' << x.first << ", " << x.second << "], ";
    }
    cout << "]\n";
}

// Simple solution - Compare each pair with all other pairs to check if they overlap.
// If overlapping, merge the second into first and remove the second
void solveSimple(vector<pair<int, int>> &intervals) {
    int size = intervals.size();
    vector<pair<int, int>>::iterator it = intervals.begin();
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(intervals[i].second < intervals[j].first) continue;
            if(intervals[i].second <= intervals[j].second and i != j) {
                intervals[i].second = intervals[j].second;
                // Remove the second pair from the list
                intervals.erase(it + j);
                // Update size
                size = intervals.size();
            }
        }
    }
    printAnswer(intervals);

}

// Better solution - Sort the intervals based on the first element
// Push the first element onto a stack
// Traverse from the first pair and check with the top element of the stack
// If it overlaps, merge them and push the new pair onto the stack
// If it doesnt, simply push it onto the stack
// TC - O(nlogn) SC - O(n)
static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

void solveUsingStack(vector<pair<int, int>> &intervals) {
    int size = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);
    stack<pair<int, int>> s;
    s.push(intervals[0]);
    for(int i = 1; i < size; ++i) {
        pair<int, int> top = s.top();
        if(top.second < intervals[i].first) {
            s.push(intervals[i]);
            continue;
        }
        if(top.second < intervals[i].second) {
            top.second = intervals[i].second;
            s.pop();
            s.push(top);
        }
    }
    vector<pair<int, int>> answer;
    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    printAnswer(answer);
}

// Space optimization - modifying the given array
// Keep an index of the element to which the comparision needs to be made
// TC - O(nlogn) SC - O(1)
void solveWithoutStack(vector<pair<int, int>> &intervals) {
    int size = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);
    // Index of the last element in output array (array[0...index - 1] contains the merged intervals in sorted manner)
    int index = 0;
    for(int i = 1; i < size; ++i) {
        // If current element overlaps with the last one
        if(intervals[index].second >= intervals[i].first) {
            // merge the current interval with the previoud one
            intervals[index].second = max(intervals[index].second, intervals[i].second);
            intervals[index].first = min(intervals[index].first, intervals[i].first);
        }
        else {
            // Update the previous element
            index++;
            intervals[index] = intervals[i];
        }
    }
    // Print the answer
    cout << "[";
    for(int i = 0; i <= index; ++i) {
        cout << '[' << intervals[i].first << ", " << intervals[i].second << "], "; 
    }
    cout << "]";
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for(int i = 0; i < n; ++i) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        intervals.push_back(temp);
    }

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
}