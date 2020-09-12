class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        vector<int> ans;
        while(l < r) {
            int p = min(height[l], height[r]) * (r - l);
            ans.push_back(p);
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};