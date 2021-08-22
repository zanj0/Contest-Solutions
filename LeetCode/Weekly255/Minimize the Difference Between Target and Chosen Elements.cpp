class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		bitset<4901> mask;
		int ret = INT_MAX;
		mask[0] = 1;
		int r = mat.size();
		int c = mat[0].size();
		for (int i = 0; i < r; i++) {
			bitset<4901> newMask;
			for (int j = 0; j < c; j++) {
				newMask |= (mask << mat[i][j]);
			}
			swap(mask, newMask);
		}
		for (int i = target, j = target;  i >= 0 || j <= 4900; i--, j++) {
			if (i >= 0 && mask[i]) {
				return target - i;
			}
			if (j <= 4900 && mask[j]) {
				return j - target;
			}
		}
		return target;
	}
};