class Solution {
public:
	int countQuadruplets(vector<int>& nums) {
		int ret = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int l = k + 1; l < n; l++) {
						ret += nums[i] + nums[j] + nums[k] == nums[l];
					}
				}
			}
		}
		return ret;
	}
};