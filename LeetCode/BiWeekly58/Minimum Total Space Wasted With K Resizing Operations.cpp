int dp[205][205];
class Solution {
public:
	int dfs(int idx, int k, vector <int>& v) {
		if (idx >= v.size()) return 0;
		if (k < 0) return 1e8;
		if (dp[idx][k] != -1) return dp[idx][k];
		int ret = 1e8;
		int maxVal = 0, sum = 0;
		for (int j = idx; j < v.size(); j++) {
			maxVal = max(v[j], maxVal);
			sum += v[j];
			int cnt = j - idx + 1;
			ret = min(ret, (cnt * maxVal) - sum + dfs(j + 1, k - 1, v));
		}

		return dp[idx][k] = ret;
	}
	int minSpaceWastedKResizing(vector<int>& nums, int k) {
		memset(dp, -1, sizeof dp);
		return dfs(0, k, nums);
	}
};