class Solution {
public:
	string makeFancyString(string s) {
		string ret = "";
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (ret.size() > 1 && ret.back() == s[i] && ret[(int)ret.size() - 2] == s[i]) continue;
			ret += s[i];
		}
		return ret;
	}
};