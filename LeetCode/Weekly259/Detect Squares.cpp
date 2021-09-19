class DetectSquares {
public:
	DetectSquares() {

	}
	map<pair<int, int>, int> cnt;
	void add(vector<int> pt) {
		pair<int, int> point;
		point.first = pt[0];
		point.second = pt[1];
		cnt[point]++;
	}
	int getVal(pair<int, int> pt) {
		// cout << pt[0] << " " << pt[1] << endl;
		return cnt.count(pt) ? cnt[pt] : 0;
	}
	int nC3(int x) {
		return (x * (x - 1) * (x - 2)) / 6;
	}
	int count(vector<int> pt) {
		pair<int, int> point;
		point.first = pt[0];
		point.second = pt[1];
		int ret = 0;
		// cout << "NOW " <<  point[0] << " " << point[1] << endl;
		for (auto& it : cnt) {
			if (it.first.first == point.first) {
				int dist = abs(point.second - it.first.second);
				if (point == it.first) {
					// ret += nC3(it.second);
					continue;
				}
				int add = it.second * getVal({point.first - dist, point.second}) * getVal({it.first.first - dist, it.first.second});
				ret += add;
				add = it.second * getVal({point.first + dist, point.second}) * getVal({it.first.first + dist, it.first.second});
				ret += add;
			}

		}

		return ret;

	}
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */