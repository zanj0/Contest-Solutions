class Solution {
public:
	bool isPrime(int n) {
		if (n % 2 == 0 && n != 2) return false;
		for (int i = 3; i * i <= n; i++) if (n % i == 0) return false;
		return n > 1;
	}
	bool isThree(int n) {
		int rootVal = sqrt(n);
		return rootVal * rootVal == n && isPrime(rootVal);
	}
};
