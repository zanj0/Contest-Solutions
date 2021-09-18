class Solution {
public:
	int getVal(int l, int r, vector <pair <int, int>>& v) {
		if (r < 0 || l > r) return 0;
		return v[r].second - (l - 1 < 0 ? 0 : v[l - 1].second);
	}
	int calc(int i, int n, vector < pair <int, int>>& v) {
		int low = i;
		int m = v.size();
		int high = m - 1;
		int req = v[i].first + n - 1;
		int val = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (v[mid].first <= req) {
				low = mid + 1;
				int before = getVal(0, i - 1, v);
				int after = getVal(mid + 1, m - 1, v);
				int between = getVal(i, mid, v) - (mid - i + 1);
				// cout << i << " " << mid << " " << before << " " << after << " " << between << endl;
				val = before + after + between;
			} else {
				high = mid - 1;
			}
		}
		return val;
	}
	int minOperations(vector<int>& nums) {
		int ret = INT_MAX;
		sort(nums.begin(), nums.end());
		map <int, int> cnt;
		for (int i : nums) cnt[i]++;
		vector < pair <int, int> > v;
		for (auto& it : cnt)v.push_back(it);
		for (int i = 1; i < v.size(); i++) v[i].second += v[i - 1].second;
		int n = nums.size();
		int m = v.size();
		int val;
		// for(auto& it : v){
		//     cout << it.first << " -- " << it.second << endl;
		// }
		// cout << calc(0, n, v) << endl;
		for (int i = 0; i < m; i++) {
			val = calc(i, n, v);
			// cout << i << " " << val << endl;
			ret = min(ret, val);
		}
		return ret;
	}
};