const int N = 1e5 + 5;
vector<int> graph[N];
typedef long long int lli;
class Solution {
public:
	lli ret, maxVal;
	int n;
	lli dfs(int node, int par) {
		lli sum = 1;
		lli prod = 1;
		for (auto& it : graph[node]) {
			if (it == par) continue;
			lli val = dfs(it, node);
			prod *= val;
			sum += val;
		}
		lli up = n - sum;
		prod *= max(up, 1ll);
		// cout << node << " " << prod << endl;
		if (prod > maxVal) {
			maxVal = prod;
			ret = 1;
		} else if (maxVal == prod) ret++;
		return sum;
	}
	int countHighestScoreNodes(vector<int>& v) {
		ret = 0;
		maxVal = 0;
		n = v.size();
		for (int i = 0; i <= n; i++) graph[i].clear();
		for (int i = 1; i < n; i++) {
			graph[i].push_back(v[i]);
			graph[v[i]].push_back(i);
		}
		dfs(0, -1);
		return ret;
	}
};