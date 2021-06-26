class Solution {
public:
	bool check(string& s, string& part) {
		int i = s.size() - 1;
		int j = part.size() - 1;
		while (j >= 0) {
			if (s[i] != part[j]) return false;
			i--;
			j--;
		}
		return true;
	}
	void remove(string& s, int cnt) {
		while (cnt--) s.pop_back();
	}
	string removeOccurrences(string s, string part) {
		string ret = "";
		int n = s.size();
		int m = part.size();
		for (int i = 0; i < n; i++) {
			ret += s[i];
			if (ret.size() >= part.size() && check(ret, part)) {
				remove(ret, m);
			}
		}
		return ret;
	}
};