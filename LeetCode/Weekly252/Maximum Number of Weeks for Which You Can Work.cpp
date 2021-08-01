typedef long long int lli;
class Solution {
public:
	long long numberOfWeeks(vector<int>& milestones) {
		lli sum = 0, maxVal = 0;
		for (int i = 0; i < milestones.size(); i++) {
			sum += milestones[i];
			maxVal = max((lli)milestones[i], maxVal);
		}
		lli rest = sum - maxVal;
		if (rest >= maxVal) return sum;
		return ((lli)2 * rest) + 1;
	}
};