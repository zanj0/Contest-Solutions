const int N = 1e4 + 5;
vector<int> graph[N];
class Solution {
public:
	int n;
	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
	}

	int getTime(int x, int time, int change) {
		// cout << x << endl;
		int ret = 0, diff;
		for (int i = 1; i <= x; i++) {
			ret += time;
			// cout << ret << " " << (ret / change) << endl;
			bool shouldChange = i  < x && (ret / change) & 1;
			if (shouldChange) {
				ret = ((ret / change) * change) + change;
			}
		}
		return ret;
	}
	vector<int> bfs(int src) {
		vector<int> ret(n + 1, INT_MAX);
		ret[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto& it : graph[node]) {
				if (ret[it] == INT_MAX) {
					ret[it] = ret[node] + 1;
					q.push(it);
				}
			}
		}
		return ret;
	}
	void out(vector<int>& v) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		this->n = n;
		for (int i = 0; i <= n; i++) graph[i].clear();
		for (auto& it : edges) {
			graph[it[0]].push_back(it[1]);
			graph[it[1]].push_back(it[0]);
		}
		vector<int> beg = bfs(1);
		vector<int> dest = bfs(n);
		int ret = getTime(beg.back() + 2, time, change);
		int val = INT_MAX;
		int smallest = beg.back();
		for (int i = 1; i <= n; i++) {
			int temp = beg[i] + dest[i];
			if (temp > smallest) {
				val = min(val, temp);
			}
		}
		// cout << val << endl;
		if (val != INT_MAX) ret = min(ret, getTime(val, time, change));
		return ret;
	}
};