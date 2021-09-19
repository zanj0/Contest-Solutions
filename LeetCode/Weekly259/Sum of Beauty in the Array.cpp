class Solution {
public:
	int sumOfBeauties(vector<int>& nums) {
		int n = nums.size();
		vector <int> right(n)   ;
		right.back() = nums.back();

		for (int i = n - 2; i >= 0; i--) {
			right[i] = min(right[i + 1], nums[i]);
		}
		int maxVal = 0;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (i - 1 >= 0 && i + 1 < n) {
				if (maxVal < nums[i] && nums[i] < right[i + 1]) ret += 2;
				else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])  ret++;
			}
			maxVal = max(maxVal, nums[i]);
		}
		return ret;
	}
};