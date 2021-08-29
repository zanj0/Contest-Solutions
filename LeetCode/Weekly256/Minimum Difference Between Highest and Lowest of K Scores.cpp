class Solution {
public:
	int minimumDifference(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int ret = INT_MAX;
		for (int i = 0, j = k - 1; j < nums.size(); j++, i++) {
			ret = min(ret, nums[j] - nums[i]);
		}
		return ret;
	}
};