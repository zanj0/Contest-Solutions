typedef long long int lli;
const lli MOD = 1e9 + 7;
class Solution {
public:
	lli mul(lli a, lli b) {
		return ((a % MOD) * (b % MOD)) % MOD;
	}
	lli fastPow(lli base, lli pow) {
		lli ret = 1;
		while (pow) {
			if (pow & 1) ret = mul(ret, base);
			base = mul(base, base);
			pow >>= 1;
		}
		return ret;
	}
	int countGoodNumbers(long long n) {
		lli even = (n + (lli)1) / (lli)2;
		/*
		    5 possibility for even positions.
		    4 possibility for odd positions.
		    Answer is multiplication of both the possibilities.
		*/
		int ret = mul(fastPow(5, even), fastPow(4, n - even));
		return ret;
	}
};