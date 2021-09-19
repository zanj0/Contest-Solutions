
class Solution {
public:
	string getString(string& s, int k) {
		string ret = "";
		vector<int> cnt(26);
		for (auto& it : s) {
			cnt[it - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			cnt[i] /= k;
			ret += string(cnt[i], (char)('a' + i));
		}
		return ret;
	}
	string ret;
	bool done;
	void check(string& p, string& s, int len, int k) {
		int cnt = 0;
		int j = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == p[j]) {
				j++;
			}
			if (j == len) {
				j = 0;
				cnt++;
			}
		}
		if (cnt >= k) {
			done = true;
			string temp = "";
			for (int i = 0; i < len; i++) {
				temp += p[i];
			}
			if (temp.size() > ret.size() || (temp.size() == ret.size() && temp > ret)) ret = temp;
		}
	}
	string longestSubsequenceRepeatedK(string s, int k) {
		ret = "";
		string p = getString(s, k);
		sort(p.begin(), p.end());

		do {
			done = false;
			for (int i = p.size(); i >= max((int)1, (int)ret.size()) && !done; i--) {
				check(p, s, i, k);
			}

		} while (next_permutation(p.begin(), p.end()));
		return ret;
	}
};