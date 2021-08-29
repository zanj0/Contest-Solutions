typedef long long int lli;
const lli MOD = 1e9 + 7;
lli mul(lli a, lli b) {
	return ((a % MOD) * (b % MOD) % MOD);
}
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD) % MOD);
}
lli fastPow(lli base, lli pow) {
	lli ret = 1;
	while (pow) {
		if (pow & 1) {
			ret = mul(ret, base);
		}
		base = mul(base, base);
		pow >>= 1;
	}
	return ret;
}
class Solution {
public:
	int getSum(int l, vector <int>& v) {
		return v.back() - v[l - 1];
	}
	int numberOfUniqueGoodSubsequences(string s) {
		int ret = 0;
		int n = s.size();



		bool zero = false;
		lli lastOneVal = 1;
		lli otherVal = 0;
		lli lastOne = n;
		lli ones = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0') zero = true;
			else {
				int zero = lastOne - i;
				// cout << i << " " << zero << " " << lastOneVal << " " << otherVal << endl;
				int newLastOneVal =  mul(zero, lastOneVal);
				newLastOneVal = add(newLastOneVal,  mul(zero - 1, otherVal));
				ret = add(ret, newLastOneVal);

				otherVal = add(otherVal, lastOneVal);
				lastOneVal = newLastOneVal;
				lastOne = i;
				// cout << ret << endl;
			}
		}
		// cout << ret << endl;
		ret = add(ret, zero);

		return ret;
	}
};