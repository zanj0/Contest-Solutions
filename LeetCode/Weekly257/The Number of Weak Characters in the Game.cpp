class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& v) {
		int ret = 0;
		int n = v.size();
		sort(v.begin(), v.end());
		int maxVal = 0;
		int j, newMaxVal;
		newMaxVal = maxVal;
		for (int i = n - 1; i >= 0; i = j) {
			j = i;
			while (j >= 0 && v[j][0] == v[i][0]) {
				newMaxVal = max(newMaxVal, v[j][1]);
				ret += v[j][1] < maxVal;
				j--;
			}
			maxVal = newMaxVal;
		}
		return ret;
	}
};