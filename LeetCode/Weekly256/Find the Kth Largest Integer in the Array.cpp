class Solution {
public:
	static bool cmp(string& a, string& b) {
		if (a.size() != b.size()) return a.size() < b.size();
		for (int i = 0; i < a.size(); i++) {
			// cout << a[i] << " " << b[i] << " " << i << endl;
			if (a[i] < b[i]) return true;
			else if (a[i] > b[i]) return false;
		}
		return false;
	}
	string kthLargestNumber(vector<string>& nums, int k) {
		sort(nums.begin(), nums.end(), cmp);
		return nums[(int)(nums.size()) - k];
	}
};