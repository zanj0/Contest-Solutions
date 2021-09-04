const int N = 2e3 + 5;
vector<int> locked(N, -1);
vector<int> graph[N];
class LockingTree {
public:
	int n;
	vector<int> par;
	void pre() {
		for (int i = 0; i < n; i++) {
			graph[i].clear();
			locked[i] = -1;
		}
	}
	LockingTree(vector<int>& parent) {
		this->n = parent.size();
		pre();
		par = parent;
		for (int i = 1; i < n; i++) {
			graph[i].push_back(parent[i]);
			graph[parent[i]].push_back(i);
		}
	}

	bool lock(int num, int user) {
		if (locked[num] == -1) {
			locked[num] = user;
			return true;
		}
		return false;
	}

	bool unlock(int num, int user) {
		if (locked[num] == user) {
			locked[num] = -1;
			return true;
		}
		return false;
	}
	void dfs(int node, int par, vector<int>& v) {
		if (locked[node] != -1) {
			v.push_back(node);
		}
		for (int i : graph[node]) {
			if (i == par) continue;
			dfs(i, node, v);
		}
	}
	bool upgrade(int num, int user) {
		vector<int> v;
		int curr = num;
		while (curr != -1) {
			if (locked[curr] != -1) return false;
			curr = par[curr];
		}
		dfs(num, par[num], v);
		if (!v.empty()) {
			locked[num] = user;
			for (int i : v) {
				locked[i] = -1;
			}
			return true;
		}
		return false;
	}
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */