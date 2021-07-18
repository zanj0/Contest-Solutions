class Solution {
public:
	long long maxPoints(vector<vector<int>>& v) {
		long long n = v.size(), m = v[0].size();

		long long ret = 0;
		vector <long long> dp(m);

		for (long long i = 0; i < n; i++) {

			vector <long long> left(m);
			vector <long long> right(m);

			for (long long j = 0; j < m; j++) {
				left[j] = dp[j] + j;
				if (j - 1 >= 0) left[j] = max(left[j], left[j - 1]);
			}

			for (long long j = m - 1; j >= 0; j--) {
				right[j] = dp[j] - j;
				if (j + 1 < m) right[j] = max(right[j], right[j + 1]);
			}
			for (long long j = 0; j < m; j++) {
				if (i == 0) {
					dp[j] = v[i][j];
				} else
					dp[j] = max(v[i][j] - j + left[j], v[i][j] + j + right[j]);
			}

		}
		return *max_element(dp.begin(), dp.end());
	}
};