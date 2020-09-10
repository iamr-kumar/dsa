class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         for nums[i], check if target - nums[i] exists in the array or not.
//         brute force - check for every possible pair if the sum is equal to the target sum
        vector<int> ans;
        map<int, int> indices;
        for(int i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];
            if(indices.find(num) != indices.end() and indices.find(num)->second != i) {
                ans.push_back(i);
                ans.push_back(indices.find(num)->second);
                return ans;
            }
            indices[nums[i]] = i;
        }
        return ans;
    }
};