class Solution {
public:
	int getCount(string& s, int mask) {
		string newS = "";
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				newS += s[i];
			}
		}
		int i = 0;
		int j = (int)newS.size() - 1;
		while (i < j) {
			if (newS[i] != newS[j]) return 0;
			i++;
			j--;
		}
		return (int)newS.size();
	}
	int maxProduct(string s) {
		int ret = 0;
		int n = s.size();
		vector<int> dp(1 << n);
		int all = (1 << n) - 1;
		for (int mask = 0; mask < (1 << n); mask++) {
			dp[mask] = getCount(s, mask);
		}
		for (int m1 = 0; m1 < (1 << n); m1++) {
			if (!dp[m1]) continue;
			for (int m2 = all ^ m1; m2; m2 = (m2 - 1) & (all ^ m1)) {
				ret = max(ret, dp[m1] * dp[m2]);
			}
		}
		return ret;
	}
};