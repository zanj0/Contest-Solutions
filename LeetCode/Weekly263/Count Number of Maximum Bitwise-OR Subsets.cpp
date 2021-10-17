
class Solution {
public:
	int getBit(int mask, int i) {
		return (mask >> i) & 1;
	}
	int countMaxOrSubsets(vector<int>& nums) {
		map<int, int> cnt;
		int n = nums.size();
		for (int i = 1; i < (1 << n); i++) {
			int val = 0;
			for (int j = 0; j < n; j++) {
				if (getBit(i, j)) {
					val |= nums[j];
				}
			}
			cnt[val]++;
		}
		return cnt.rbegin()->second;
	}
};