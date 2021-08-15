typedef long long int lli;
const lli MOD = 1e9 + 7;
lli mul(lli a, lli b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
lli fastPow(lli base, lli power) {
	lli ret = 1;
	while (power) {
		if (power % 2 == 1) ret = mul(ret, base);
		base = mul(base, base);
		power /= 2;
	}
	return ret;
}
class Solution {
public:
	int minNonZeroProduct(int p) {
		lli ret = 1;
		lli lastVal = ((lli)1 << (lli)p) - 1;
		ret = lastVal;
		lli other = lastVal - 1;
		if (other)ret = mul(ret, fastPow(other, ((lli)1 << (lli)(p - 1)) - 1));
		return ret;
	}
};