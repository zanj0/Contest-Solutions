class Solution {
public:
	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
	}
	int minSwaps(string s) {
		int ret = 0;
		int open = 0, close = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') open++;
			else {
				if (open) open--;
				else close++;
			}
		}
		return ceilDiv(close, 2);
	}
};