// Problem - Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sumSoFar = 0, maxElement = INT_MIN;
        for(int i = 0; i < n; ++i) {
            sumSoFar = max(sumSoFar + nums[i], 0);
            maxSum = max(maxSum, sumSoFar);
            maxElement = max(maxElement, nums[i]);
        }
        maxSum = maxSum <= 0 ? maxElement : maxSum;
        return maxSum;
    }
};