typedef long long int lli;
const lli MOD = 1e9 + 7;
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
const lli inf = 1e18;
class Solution {
public:
	vector<vector<pair<lli, lli>>> graph;
	int n;
	lli dijkstra(int src) {
		vector <lli> dist(n, inf);
		vector <lli> ways(n);
		ways[0] = 1;
		dist[0] = 0;
		priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq;
		pq.push({0, 0});
		while (!pq.empty()) {
			pair<lli, lli> temp = pq.top();
			pq.pop();
			lli c = temp.first;
			lli node = temp.second;
			if (dist[node] < c) continue;

			for (auto& it : graph[node]) {
				lli newCost = c + it.second;
				if (dist[it.first] > newCost) {
					dist[it.first] = newCost;
					ways[it.first] = ways[node];
					pq.push({newCost, it.first});
				} else if (dist[it.first] == newCost) {
					ways[it.first] = add(ways[node], ways[it.first]);
				}
			}
		}
		return ways.back();
	}

	int countPaths(int n, vector<vector<int>>& roads) {
		this->n = n;
		graph = vector<vector<pair<lli, lli>>>(n);
		lli ret = 0;
		for (auto& it : roads) {
			graph[it[0]].push_back({it[1], it[2]});
			graph[it[1]].push_back({it[0], it[2]});
		}

		return dijkstra(0);
	}
};