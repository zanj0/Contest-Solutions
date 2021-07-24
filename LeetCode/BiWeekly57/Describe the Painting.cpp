class Solution {
public:
	vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
		vector <long long> colours(1e5 + 5);
		set <long long> open, close;
		for (auto& it : segments) {
			colours[it[0]] += it.back();
			colours[it[1]] -= it.back();
			open.insert(it[0]);
			close.insert(it[1]);
		}
		vector < vector <long long> > ret;
		int last = -1;
		for (int i = 1; i <= 1e5 + 1; i++) {
			colours[i] += colours[i - 1];
			if (close.count(i)) {
				ret.back()[1] = i;
			}
			if (open.count(i)) {
				if (!ret.empty() && ret.back()[1] == -1) ret.back()[1] = i;
				ret.push_back({i, -1, colours[i]});
			} else if (colours[i] && ret.back()[1] != -1) {
				ret.push_back({i, -1, colours[i]});
			}
		}
		return ret;
	}
};