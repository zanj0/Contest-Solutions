class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector <int> ret(n);
		int j = nums.size() - 1;
		for (int i = 0; i < n; i += 2) ret[i] = nums[j--];
		for (int i = 1; i < n; i += 2) ret[i] = nums[j--];
		return ret;
	}
};