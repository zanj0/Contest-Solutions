const int N = 1e5 + 5;
vector<int> graph[N];
int out[N], in[N], timer = 0;
set <int> s;

class Solution {
public:
	void dfs(int node, int par) {
		timer++;
		in[node] = timer;
		for (int i : graph[node]) {
			if (i == par) continue;
			dfs(i, node);
		}
		timer++;
		out[node] = timer;
	}
	bool isAnc(int a, int b) {
		return in[a] <= in[b] && out[a] >= out[b];
	}
	void dfs2(int node, vector<int>& par, set<int>& visited, vector<int>& nums) {
		if (s.count(nums[node])) s.erase(nums[node]);
		visited.insert(node);
		for (int i : graph[node]) {
			if (i == par[node] || visited.count(i)) continue;
			dfs2(i, par, visited, nums);
		}
	}
	vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
		int n = parents.size();
		timer = 0;
		s.clear();
		vector<int> ret(n, 1);
		int zero = -1;
		for (int i = 0; i < n; i++) {
			graph[i].clear();
			if (nums[i] == 1) zero = i;
		}
		if (zero == -1) return ret;
		for (int i = 1; i < n; i++) {
			graph[parents[i]].push_back(i);
			graph[i].push_back(parents[i]);
		}
		for (int i = 1; i <= n + 1; i++) {
			s.insert(i);
		}
		dfs(0, -1);

		for (int i = 0; i < n; i++) {
			if (isAnc(zero, i)) {
				if (s.count(nums[i])) s.erase(nums[i]);
			}
			if (!isAnc(i, zero)) {
				ret[i] = 1;
			}
		}
		ret[zero] = *(s.begin());
		int curr = parents[zero];
		set<int> visited;
		while (curr != -1) {
			dfs2(curr, parents, visited, nums);
			ret[curr] = *(s.begin());
			curr = parents[curr];
		}
		return ret;
	}
};