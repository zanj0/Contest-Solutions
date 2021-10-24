class Solution {
public:
	bool check(int x) {
		vector<int> cnt(10);
		while (x) {
			cnt[x % 10]++;
			x /= 10;
		}
		for (int i = 0; i <= 9; i++) {
			if (cnt[i] && cnt[i] != i) return false;
		}
		return true;
	}
	int nextBeautifulNumber(int n) {
		n++;
		while (!(check(n)))n++;
		return n;
	}
};