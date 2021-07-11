class Solution {
public:
	map < char, vector <int> > idx;
	bool isPossible(char end, char mid) {
		if (!idx.count(end) || !idx.count(mid) || idx[end].size() < 2) return false;
		int firstPos = idx[end][0];
		int secondPos;
		auto itr = upper_bound(idx[mid].begin(), idx[mid].end(), firstPos);
		if (itr == idx[mid].end()) return false;
		secondPos = *itr;
		int thirdPos = idx[end].back();
		return firstPos < secondPos && secondPos < thirdPos;

	}
	int countPalindromicSubsequence(string s) {
		int n = s.size();
		int ret = 0;
		for (int i = 0; i < n; i++) {
			idx[s[i]].push_back(i);
		}
		for (char side = 'a'; side <= 'z'; side++) {
			for (char mid = 'a'; mid <= 'z'; mid++) {
				ret += isPossible(side, mid);
			}
		}
		return ret;
	}
};