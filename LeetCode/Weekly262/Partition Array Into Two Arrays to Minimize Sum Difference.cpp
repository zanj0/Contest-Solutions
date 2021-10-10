int dp[1 << 15];
typedef long long int lli;
class Solution {
public:
	int getBit(int mask, int i) {
		return (mask >> i) & 1;
	}
	lli getSum(int mask, vector<int>& v) {
		int n = v.size();
		lli ret = 0;
		for (int i = 0; i < n; i++) {
			if (getBit(mask, i)) {
				ret += v[i];
			}
		}
		return ret;
	}
	bool flag = false;
	void pre() {
		if (flag) return ;
		for (int i = 0; i < (1 << 15); i++) {
			dp[i] = __builtin_popcount(i);
		}
		flag = true;
	}
	int minimumDifference(vector<int>& nums) {
		int n = nums.size() / 2;
		int ret = INT_MAX;
		vector<int> first, second;
		int sum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < nums.size(); i++) {
			if (i < n) first.push_back(nums[i]);
			else second.push_back(nums[i]);
		}
		unordered_map<int, vector<lli>> sum1, sum2;
		pre();
		for (int i = 0; i < (1 << n); i++) {
			lli f = getSum(i, first);
			lli s = getSum(i, second);
			int cnt = dp[i];
			sum1[cnt].push_back(f);
			sum2[cnt].push_back(sum - 2 * s);
		}
		for (int i = 1; i <= n; i++) {
			sort(sum1[i].begin(), sum1[i].end());
			sort(sum2[n - i].begin(), sum2[n - i].end());
		}
		for (int i = 1; i <= n; i++) {
			int j = 0;
			for (auto& it : sum1[i]) {
				while (j < sum2[n - i].size() && sum2[n - i][j] <= 2 * it) {
					ret = min(ret, (int)abs(sum2[n - i][j] - (2 * it)));
					j++;
				}
				if (j < sum2[n - i].size()) ret = min(ret, (int)abs(sum2[n - i][j] - (2 * it)));
			}
		}
		return ret;
	}
};