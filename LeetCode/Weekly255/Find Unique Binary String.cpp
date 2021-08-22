class Solution {
public:
	string makeString(int val, int n) {
		string ret = "";
		while (val) {
			int digit = val % 2;
			ret += (char)(digit + '0');
			val >>= 1;
		}
		while (ret.size() < n) ret += '0';
		reverse(ret.begin(), ret.end());
		return ret;
	}
	string findDifferentBinaryString(vector<string>& nums) {
		set <string> has(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < (1 << n); i++) {
			string temp = makeString(i, n);
			if (!has.count(temp)) return temp;
		}
		return "";
	}
};