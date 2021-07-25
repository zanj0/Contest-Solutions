int dp[10][1 << 8];
class Solution {
public:
	int getScore(vector <int>& v1, vector <int>& v2) {
		int ret = 0;
		for (int i = 0; i < v1.size(); i++) {
			ret += v1[i] == v2[i];
		}
		return ret;
	}
	int dfs(int i, vector < vector <int> >& v1, vector < vector <int> >& v2, int mask) {
		if (i >= v1.size()) return 0;
		if (dp[i][mask] != -1) return dp[i][mask];
		int ret = 0;
		for (int j = 0; j < v2.size(); j++) {
			if ((mask >> j) & 1) continue;
			ret = max(ret, getScore(v1[i], v2[j]) + dfs(i + 1, v1, v2, mask ^ (1 << j)));
		}
		return dp[i][mask] = ret;
	}
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		memset(dp, -1, sizeof dp);
		return dfs(0, students, mentors, 0);
	}
};