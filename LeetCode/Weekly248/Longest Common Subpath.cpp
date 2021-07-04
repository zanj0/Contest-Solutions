typedef long long int lli;
const lli MOD = 1e11 + 7;
const lli N = 1e5 + 5;
const lli BASE = 100007;
lli powers[N];
class Solution {
public:
	lli mul(lli aa, lli bb) {
		__int128 a = aa, b = bb; // Changing data type to prevent overflow.
		return (lli)((a % MOD) * (b % MOD)) % MOD;
	}

	lli add(lli a, lli b) {
		return ((a % MOD) + (b % MOD)) % MOD;
	}

	lli sub(lli a, lli b) {
		return ((a % MOD) - (b % MOD) + MOD) % MOD;
	}

	void pre() {
		powers[0] = 1;
		for (lli i = 1; i < N; i++) {
			powers[i] = mul(powers[i - 1], BASE);
		}
	}

	bool isLenPossible(lli len, vector < vector <int> >& paths) {
		lli n = paths.size();
		set <lli> prev;
		for (lli i = 0; i < n; i++) {
			if (paths[i].size() < len) return false;
			lli hash = 0;
			set <lli> curr;
			for (lli j = 0; j < len; j++) {
				hash = mul(hash, BASE);
				hash = add(hash, paths[i][j]);
			}
			if (i == 0) {
				curr.insert(hash);
			} else {
				if (prev.count(hash)) curr.insert(hash);
			}
			for (lli j = len; j < paths[i].size(); j++) {
				hash = sub(hash, mul(paths[i][j - len] , powers[len - 1]));
				hash = mul(hash, BASE);
				hash = add(hash, paths[i][j]);
				if (i == 0) {
					curr.insert(hash);
				} else {
					if (prev.count(hash)) curr.insert(hash);
				}
			}
			if (curr.size() == 0) return false;
			prev = curr;
		}
		return prev.size() > 0;
	}

	int longestCommonSubpath(int n, vector<vector<int>>& paths) {
		lli ret = 0;
		lli low = 1;
		lli high = INT_MAX;
		lli m = paths.size();
		pre();
		for (lli i = 0; i < m; i++) {
			high = min(high, (lli)paths[i].size());
			for (int j = 0; j < paths[i].size(); j++) paths[i][j]++;
		}
		while (low <= high) {
			lli mid = low + (high - low) / 2;
			if (isLenPossible(mid, paths)) {
				ret = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return ret;
	}
};