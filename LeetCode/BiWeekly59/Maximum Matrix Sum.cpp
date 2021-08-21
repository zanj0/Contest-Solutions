typedef long long int lli;
class Solution {
public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		lli ret = 0;
		lli sign = 0;
		int r = matrix.size();
		int c = r ? matrix[0].size() : 0;
		lli minVal = INT_MAX;
		bool hasZero = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ret += abs(matrix[i][j]);
				minVal = min(minVal, (lli)abs(matrix[i][j]));
				sign += matrix[i][j] < 0;
				hasZero = hasZero | matrix[i][j] == 0;
			}
		}
		if (!hasZero && (sign & 1)) ret -= 2 * minVal;
		return ret;
	}
};