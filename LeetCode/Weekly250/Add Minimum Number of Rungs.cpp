class Solution {
public:
	int ceilDiv(int a, int b) {
		return a / b;
	}
	int addRungs(vector<int>& v, int dist) {
		int ret = 0;
		int last = 0;
		for (int i = 0; i < v.size(); i++) {
			ret += ceilDiv(max(0, (v[i] - last - 1)), dist);
			last = v[i];
		}
		return ret;
	}
};