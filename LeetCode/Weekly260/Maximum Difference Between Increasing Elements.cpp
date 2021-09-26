class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ret = -1;
        int minVal = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (minVal != nums[i])ret = max(ret, nums[i] - minVal);
            minVal = min(nums[i], minVal);
        }
        return ret;
    }
};