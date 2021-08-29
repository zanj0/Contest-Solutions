int dp[1 << 14][20];
class Solution {
public:
	int org, req;
	int dfs(int mask, int sum, vector <int>& v) {
		if (mask == req) return 1;
		if (dp[mask][sum] != -1) return dp[mask][sum];
		// Do in same session.
		int ret = INT_MAX;
		for (int idx = 0; idx < v.size(); idx++) {
			if ((mask >> idx) & 1) continue;
			if (sum - v[idx] >= 0) {
				ret = min(ret, dfs(mask | (1 << idx),  sum - v[idx], v));
			}
			// New session.
			ret = min(ret, 1 + dfs(mask | (1 << idx),  org - v[idx], v));
		}
		return dp[mask][sum] = ret;
	}
	int minSessions(vector<int>& tasks, int sessionTime) {
		memset(dp, -1, sizeof dp);
		req = ((1 << (int)tasks.size()) - 1);
		org = sessionTime;
		return dfs(0, sessionTime, tasks);
	}
};