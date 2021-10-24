class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		map <int, int> in;
		vector<int> dist(n, -1);
		vector<vector<int>> graph(n);
		int idx = 0;
		for (auto& it : relations) {
			it[0]--;
			it[1]--;
			graph[it[0]].push_back(it[1]);
			in[it[1]]++;

		}
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (!in[i]) {
				q.push(i);
				dist[i] = time[i];
			}
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto &it : graph[node]) {
				in[it]--;
				dist[it] = max(dist[it], dist[node] + time[it]);
				if (!in[it])q.push(it);
			}
		}
		int ret = *max_element(dist.begin(), dist.end());
		return ret;
	}
};