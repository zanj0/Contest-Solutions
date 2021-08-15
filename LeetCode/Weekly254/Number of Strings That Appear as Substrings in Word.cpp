class Solution {
public:
	bool ok(string word, string patt) {
		for (int i = 0; i < patt.size(); i++) {
			int j = 0;
			int ni = i;
			while (j < word.size() && ni < patt.size() && word[j] == patt[ni]) {
				ni++;
				j++;
			}
			if (j == word.size()) return true;
		}
		return false;
	}
	int numOfStrings(vector<string>& patterns, string word) {
		int ret = 0;
		for (auto& it : patterns) {
			ret += ok(it, word);
		}
		return ret;
	}
};

