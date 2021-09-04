typedef long long int lli;
const lli MOD = 1e9 + 7;

lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

lli mul(lli a, lli b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}

lli fastPow(lli base, lli power) {
	lli ret = 1;
	while (power) {
		if (power & 1) {
			ret = mul(ret, base);
		}
		base = mul(base, base);
		power >>= 1;
	}
	return ret;
}

class Solution {
public:
	map <int, int> idx, numToMask, cnt;

	bool isPrime(int n) {
		if (n % 2 == 0 && n > 2) return false;
		for (int i = 3; i * i <= n; i++) {
			if (n % i == 0) return false;
		}
		return n > 1;
	}

	void populate(int val) {
		int mask = 0;
		int org = val;
		cnt[org]++;
		for (auto& it : idx) {
			int cnt = 0;
			while (val % it.first == 0) {
				val /= it.first;
				cnt++;
			}
			if (cnt == 1) {
				mask |= (1 << it.second);
			} else if (cnt >= 2) return;
		}
		numToMask[org] = mask;
	}

	int numberOfGoodSubsets(vector<int>& nums) {
		vector<lli> dp(1 << 10);
		int oneCount = 0;
		int curr = 0;
		for (int i = 2; i <= 30; i++) {
			if (isPrime(i)) {
				idx[i] = curr;
				curr++;
			}
		}
		for (int i : nums) {
			populate(i);
		}
		dp[0] = 1;
		for (auto& i : cnt) {
			int val = i.first;
			if (val == 1) {
				oneCount = i.second;
				continue;
			}
			if (!numToMask.count(val)) continue;
			int mask = numToMask[val];
			for (int j = (1 << 10) - 1; j >= 0 ; j--) {
				if (mask & j) continue;
				dp[mask | j] = add(dp[mask | j], mul(i.second, dp[j]));
			}
		}
		lli sum = 0;
		for (int i = 1; i < dp.size(); i++) {
			sum = add(sum, dp[i]);
		}
		return mul(fastPow(2, oneCount), sum);
	}
};