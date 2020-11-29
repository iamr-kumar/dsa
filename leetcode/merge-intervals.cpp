#include<bits/stdc++.h>

using namespace std;

// Explanation same as merge intervals in arrays section

class Solution {
public:
    static bool compare(const vector<int> a, const vector<int> b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
       sort(intervals.begin(), intervals.end(), compare);
        int index = 0;
        for(int i = 1; i < size; ++i) {
            // If current element overlaps with the last one
            if(intervals[index][1] >= intervals[i][0]) {
                // merge the current interval with the previoud one
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
                intervals[index][0] = min(intervals[index][0], intervals[i][0]);
            }
            else {
                // Update the previous element
                index++;
                intervals[index] = intervals[i];
            }
        }
        
        vector<vector<int>> answer;
        for(int i = 0; i <= index; ++i) {
            answer.push_back(intervals[i]);
        }
        return answer;
        
    }
};