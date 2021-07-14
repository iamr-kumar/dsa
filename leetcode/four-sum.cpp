class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        if(n < 4) 
            return answer;
        for(int i = 0; i < n - 3; ++i) {
            if(i > 0 and nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if(j > i + 1 and nums[j] == nums[j - 1])
                    continue;
                int low = j + 1, high = n - 1;
                while(low < high ){
                    int sum = nums[i] + nums[j] + nums[low] + nums[high];
                    if(sum == target) {
                        answer.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                        while(low < high and nums[low] == nums[low - 1]) low++;
                        while(low < high and nums[high] == nums[high + 1]) high--;
                    } else if(sum < target) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return answer;
    }
};