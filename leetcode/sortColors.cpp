// Problem Statement:
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            switch(nums[mid]) {
                case 0: 
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
            }
        }
    }
};