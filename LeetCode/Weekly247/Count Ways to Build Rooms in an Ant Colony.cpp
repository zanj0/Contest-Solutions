typedef long long int lli;
const lli N = 1e5 + 5;
const lli MAX = 1e5 + 5;
const lli MOD = 1e9 + 7;
int sizeOfSubtree[N], dp[N]; // dp[node] is the number of ways to create rooms with node as the root of the tree.
vector <int> graph[N];
lli fac[MAX], finv[MAX];
lli inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (lli i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
lli COM(lli n, lli k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
lli mul(lli a, lli b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
class Solution {
public:
	void pre(int n) {
		COMinit();
		for (int i = 0; i <= n; i++) {
			graph[i].clear();
			dp[i] = 0;
			sizeOfSubtree[i] = 0;
		}
	}
	void dfs(int node, int pre) {
		sizeOfSubtree[node] = 1;
		for (auto& it : graph[node]) {
			if (it == pre) continue;
			dfs(it, node);
			sizeOfSubtree[node] += sizeOfSubtree[it];
		}
	}
	void dfs1(int node, int pre) {
		dp[node] = 1;
		int totalNodes = 0;
		for (auto& it : graph[node]) {
			if (it == pre) continue;
			dfs1(it, node);
			totalNodes += sizeOfSubtree[it];
			lli tmp = mul(dp[it], COM(totalNodes, sizeOfSubtree[it])); // number of array combinations * merging ways of a single array combination.
			dp[node] = mul(dp[node], tmp);
		}
	}
	int waysToBuildRooms(vector<int>& prevRoom) {
		int n = prevRoom.size();
		pre(n);
		for (int i = 1; i < n; i++) {
			graph[prevRoom[i]].push_back(i);
			graph[i].push_back(prevRoom[i]);
		}
		dfs(0, -1);
		dfs1(0, -1);
		return dp[0];
	}
};