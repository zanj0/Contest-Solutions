typedef long long int lli;
const int N = 1e5 + 5;
int dp[N][5]; // {idx, req}
const int MOD = 1e9 + 7;
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
class Solution {
public:
	int dfs(int idx, int req, vector <int>& v) {
		if (idx >= v.size()) return req == 3;
		if (dp[idx][req] != -1) return dp[idx][req];
		lli ret = dfs(idx + 1, req, v); // Don't take.
		if (v[idx] == req) {
			// Requirement reached.
			ret = add(ret, dfs(idx + 1, req + 1, v)); // New requirement.
			ret = add(ret, dfs(idx + 1, req, v)); // Don't change requirement.
		}
		return dp[idx][req] = ret;
	}
	int countSpecialSubsequences(vector<int>& nums) {
		memset(dp, -1, sizeof dp);
		return dfs(0, 0, nums);
	}
};