typedef long long int lli;
const lli MOD = 1e9 + 7;
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
lli sub(lli a, lli b) {
	return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
const int N = 3600;
int same[N][N];
class Solution {
public:
	string s;
	int cmp(int i, int j) {
		if (j >= s.size()) return 0;
		if (same[i][j] != -1) return same[i][j];
		return same[i][j] = s[i] == s[j] ? 1 + cmp(i + 1, j + 1) : 0;
	}
	int cmp(int i, int j, int len) {
		int l = cmp(i, j);
		if (l >= len) return 1;
		return s[i + l] < s[j + l];
	}
	int numberOfCombinations(string num) {
		int n = num.size();
		if (num[0] == '0') return 0;
		memset(same, -1, sizeof same);
		s = num;
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 0; i < n; i++) dp[0][i] = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') {
				dp[i] = dp[i - 1];
				continue;
			}
			for (int j = i; j < n; j++) {
				int len = j - i + 1;
				int prevStart = i - 1 - len + 1;
				int curr = 0;
				if (prevStart < 0) {
					curr = dp[i - 1][i - 1];
				} else {
					curr = sub(dp[i - 1][i - 1], dp[prevStart][i - 1]);
					if (cmp(prevStart, i, len)) {
						int val = prevStart == 0 ? dp[prevStart][i - 1] : sub(dp[prevStart][i - 1], dp[prevStart - 1][i - 1]);
						curr = add(curr, val);
					}
				}
				dp[i][j] = add(dp[i - 1][j], curr);
			}
		}
		return dp[n - 1][n - 1];
	}
};