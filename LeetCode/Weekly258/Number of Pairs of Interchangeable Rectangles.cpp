typedef long long int lli;
class Solution {
public:
	long long interchangeableRectangles(vector<vector<int>>& rectangles) {
		map<vector<int>, lli> cnt;
		lli ret = 0;
		for (auto& it : rectangles) {
			lli g = __gcd(it[0], it[1]);
			it[0] /= g;
			it[1] /= g;
			ret += cnt[it];
			cnt[it]++;
		}
		return ret;
	}
};