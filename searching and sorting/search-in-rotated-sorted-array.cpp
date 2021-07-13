class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        int low = 0, high = n - 1;
        int first = nums[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int val = nums[mid];
            if(val == target) {
                return mid;
            }
            bool me = first <= val;
            bool dest = first <= target;
            if(me == dest) {
                if(val < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if(me) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }   
        return -1;
    }
};