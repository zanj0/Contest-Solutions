typedef long long int lli;
const int N = 1e5 + 5;
lli dp[N][2]; // {number of elements considered, flag value to represent odd index(1) or even index(0)}
class Solution {
public:
	lli dfs(int idx, int type, vector <int>& nums) {
		if (idx >= nums.size()) return 0;
		if (dp[idx][type] != -1) return dp[idx][type];
		lli ret = dfs(idx + 1, type, nums); // Not considering the current element.
		// Considering the current element.
		if (type == 1) {
			// Odd position.
			ret = max(ret, (lli) - nums[idx] + dfs(idx + 1, 0, nums));
		} else {
			// Even position.
			ret = max(ret, (lli)nums[idx] + dfs(idx + 1, 1, nums));
		}
		return dp[idx][type] = ret;
	}
	long long maxAlternatingSum(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			dp[i][0] = dp[i][1] = -1;
		}
		return dfs(0, 0, nums);
	}
};