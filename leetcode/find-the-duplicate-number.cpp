// Problem Statement - Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

//There is only one duplicate number in nums, return this duplicate number.

#include<bits/stdc++.h>

using namespace std;

// Explanation same as the duplicates question in arrays section
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};