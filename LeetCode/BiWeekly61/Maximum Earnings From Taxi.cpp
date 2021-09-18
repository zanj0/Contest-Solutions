typedef long long int lli;

class Solution {
public:
	bool static cmp(vector <int>& a, vector <int>& b) {
		return a[1] < b[1];
	}
	long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
		sort(rides.begin(), rides.end(), cmp);

		vector <lli> dp(rides.size());
		for (int i = 0; i < rides.size(); i++) {
			int low = 0;
			int high = i - 1;
			lli val = 0;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (rides[mid][1] <= rides[i][0]) {
					val = dp[mid];
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			dp[i] = val + rides[i][1] - rides[i][0] + rides[i].back();
			if (i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);
		}
		return dp.back();

	}
};