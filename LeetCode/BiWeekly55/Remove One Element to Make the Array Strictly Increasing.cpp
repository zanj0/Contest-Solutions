class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		int n = nums.size();
		vector <bool> rightIncreasing(n);
		rightIncreasing.back() = true;
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1] && rightIncreasing[i + 1]) {
				rightIncreasing[i] = true;
			}
		}
		bool leftIncreasing = true;
		if (rightIncreasing[0]) return true; // Array is already in increasing order.
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (i + 1 < n && leftIncreasing && rightIncreasing[i + 1] && last < nums[i + 1]) return true;
			else if (i == n - 1 && leftIncreasing) return true;
			leftIncreasing = leftIncreasing && ( i - 1 >= 0 ? nums[i] > nums[i - 1] : true);
			last = nums[i];
		}
		return false;
	}
};