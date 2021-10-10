class Solution {
public:
	int minOperations(vector<vector<int>>& grid, int x) {
		int r = grid.size();
		int c = grid[0].size();
		vector<int> v;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] % x != grid[0][0] % x) {

					return -1;
				}

				v.push_back(grid[i][j]);
			}
		}
		int ret = INT_MAX;
		sort(v.begin(), v.end());
		int n = v.size();
		vector<int> suff(n);
		for (int i = n - 1; i >= 0; i--) {
			suff[i] = v[i];
			if (i + 1 < n) suff[i] += suff[i + 1];
		}
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int leftCnt = i;
			int rightCnt  = n - i - 1;
			int op1 = (i * v[i]) - sum;
			int op2 =  (i + 1 < n ? suff[i + 1] : 0) - rightCnt * v[i];
			op1 /= x;
			op2 /= x;
			ret = min(ret, op1 + op2 );
			sum += v[i];
		}
		return ret;
	}
};