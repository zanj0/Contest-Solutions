const int N = 1e3 + 5;
vector < pair <int, int> > graph[N];
class Solution {
public:
	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
		int n = passingFees.size();
		priority_queue < vector < int >, vector < vector <int> >, greater < vector <int> > > pq;
		vector <int> cost(n, INT_MAX);
		vector <int> time(n, INT_MAX);
		for (int i = 0; i <= n; i++) graph[i].clear();
		for (auto& edge : edges) {
			graph[edge[0]].push_back({edge[1], edge[2]});
			graph[edge[1]].push_back({edge[0], edge[2]});
		}
		pq.push({passingFees[0], 0, 0}); // cost, time, node
		bool ok = false;
		while (!pq.empty()) {
			ok = false;
			vector <int> curr = pq.top();
			pq.pop();
			int node = curr[2];
			int currTime = curr[1];
			int currCost = curr[0];
			if (cost[node] > currCost) {
				cost[node] = currCost;
				time[node] = currTime;
				ok = true;
			} else if (time[node] > currTime) {
				time[node] = currTime;
				ok = true;
			}
			if (node == n - 1) return currCost;
			if (!ok) continue;
			for (auto& it : graph[node]) {
				int nxtNode = it.first;
				int nxtCost = currCost + passingFees[nxtNode];
				int nxtTime = currTime + it.second;
				if (nxtTime <= maxTime) {
					if (nxtCost < cost[nxtNode] || nxtTime < time[nxtNode]) {
						pq.push({nxtCost, nxtTime, nxtNode});
					}
				}
			}
		}
		return -1;
	}
};