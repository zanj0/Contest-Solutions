class Solution {
public:
	bool punctuation(string& s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.' || s[i] == '!' || s[i] == ',') {
				return i == (int)s.size() - 1;
			}

		}
		return true;
	}
	bool other(string& s) {
		int cnt = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-') {
				cnt++;
				if (i == 0 || i == (int)s.size() - 1) return false;
				if (!isalpha(s[i - 1]) || !isalpha(s[i + 1])) return false;
			}
			if (s[i] >= '0' && s[i] <= '9') return false;
		}
		return cnt <= 1 && punctuation(s);
	}
	int countValidWords(string s) {
		int ret = 0;
		string word = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {

				if (!word.empty() && other(word)) {

					ret++;
				}

				word = "";

			} else {
				word += s[i];
			}
		}
		if (!word.empty() && other(word)) {ret++;}
		return ret;
	}
};