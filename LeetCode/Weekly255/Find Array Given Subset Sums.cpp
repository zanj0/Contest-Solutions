class Solution {
public:
	int maxVal, secondMaxVal;
	vector <int> ret;
	void getMax(map<int, int>& cnt) {
		auto it = cnt.rbegin();
		maxVal = it->first;
		if (it->second > 1) {
			secondMaxVal = maxVal;
			return;
		}
		it++;
		secondMaxVal = it->first;
	}
	void deleteFromMap(map<int, int>& cnt, int val) {
		cnt[val]--;
		if (!cnt[val]) cnt.erase(val);
	}
	bool dfs(map<int, int>& cnt, int n) {
		if (!cnt.count(0)) return false;
		if (n == 0) return true;
		map<int, int> cnt1, cnt2;
		getMax(cnt);
		int diff = maxVal - secondMaxVal;

		if (!cnt.count(diff) && !cnt.count(-diff)) return false;
		while (!cnt.empty()) {
			auto it = cnt.begin();
			cnt1[it->first]++;
			int other = it->first + diff;
			deleteFromMap(cnt, it->first);
			if (!cnt.count(other)) return false;
			cnt2[other]++;
			deleteFromMap(cnt, other);
		}
		if (cnt1.count(0) && cnt2.count(diff)) {
			bool ok = dfs(cnt1, n - 1);
			if (ok) {
				ret.push_back(diff);
				return true;
			}
		}
		if (cnt1.count(-diff) && cnt2.count(0)) {
			bool ok = dfs(cnt2, n - 1);
			if (ok) {
				ret.push_back(-diff);
				return true;
			}
		}
		return false;
	}
	vector<int> recoverArray(int n, vector<int>& sums) {
		map<int, int> cnt;
		for (int i : sums) {
			cnt[i]++;
		}
		dfs(cnt, n);
		return ret;
	}
};