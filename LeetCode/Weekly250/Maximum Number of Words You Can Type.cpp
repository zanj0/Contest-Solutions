class Solution {
public:
	int canBeTypedWords(string s, string s2) {
		set <char> bad;
		for (auto& it : s2) {
			bad.insert(it);
		}
		int ret = 0;
		bool ok = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				ret += ok;
				ok = true;
			} else {
				if (bad.count(s[i])) ok = false;
			}
		}
		ret += ok;
		return ret;

	}
};