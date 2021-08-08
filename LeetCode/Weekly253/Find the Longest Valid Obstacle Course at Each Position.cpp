class Solution {
public:
	vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		vector <int> ret;
		vector <int> seq;
		for (auto& it : obstacles) {
			int low = 0;
			int high = (int)seq.size() - 1;
			int pos = 0;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (seq[mid] <= it) {
					pos = mid + 1;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			ret.push_back(pos + 1);
			if (pos >= (int)seq.size()) seq.push_back(it);
			else seq[pos] = min(seq[pos], it);
		}
		return ret;
	}
};