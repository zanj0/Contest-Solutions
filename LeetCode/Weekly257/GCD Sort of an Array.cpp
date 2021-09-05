class UnionFind {
public:
	int* rank;
	int* parent;
	int n;
	UnionFind(int n) {
		this->n = n;
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int getParent(int x) {
		if (parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	bool unite(int a, int b) {
		int parA = getParent(a);
		int parB = getParent(b);
		if (parA == parB) return false;
		if (rank[parA] >= rank[parB]) {
			rank[parA] += rank[parB];
			parent[parB] = parA;
		} else {
			rank[parB] += rank[parA];
			parent[parA] = parB;
		}
		return true;
	}
};

class Solution {
public:
	map <int, vector <int>>divs;
	void fillDivs(int idx, int val) {
		int curr = val;
		for (int i = 2; i * i <= val; i++) {
			if (curr % i == 0) {

				divs[i].push_back(idx);
				while (curr % i == 0) curr /= i;
			}
		}
		if (curr > 1) divs[curr].push_back(idx);
	}
	bool gcdSort(vector<int>& nums) {
		int n = nums.size();
		UnionFind uf = UnionFind(n + 5);
		for (int i = 0; i < n; i++) {
			fillDivs(i, nums[i]);
		}
		for (auto& it : divs) {
			for (int i = 0; i < it.second.size(); i++) {
				// cout << it.first << " " << it.second[i] << endl;
				if (i) uf.unite(it.second[i - 1], it.second[i]);
			}
		}
		vector<pair <int, int>> v;
		for (int i = 0; i < n; i++) {
			v.push_back({nums[i], i});
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (uf.getParent(i) != uf.getParent(v[i].second)) return false;
		}
		return true;
	}
};