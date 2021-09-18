class Solution {
public:
	vector<int> findOriginalArray(vector<int>& v) {
		sort(v.begin(), v.end());
		map <int, int> has;
		for (int i : v) has[i]++;
		int n = v.size();
		vector <int> ret;
		int i = 0, j = n / 2;
		while (i < n) {
			if (has[v[i]]) {
				has[v[i]]--;
				if (has[v[i] * 2]) {
					has[v[i] * 2]--;
					ret.push_back(v[i]);
				} else return {};

			}
			i++;
		}
		// cout << has.size() << endl;
		// cout << ret.size() << endl;
		// for(int i : ret){
		//     cout << i << " - " ;
		// }
		// cout << endl;
		if (ret.size() == n / 2) return ret;
		return {};
	}
};