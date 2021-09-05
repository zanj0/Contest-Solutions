typedef long long int lli;
const lli MOD = 1e9 + 7;
lli add(lli a, lli b) {
	return (a % MOD) + (b % MOD) % MOD;
}
lli sub(lli a, lli b) {
	return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
class Solution {
public:
	int firstDayBeenInAllRooms(vector<int>& nextVisit) {
		unordered_map<int, int> states;
		unordered_set<int> visited;
		queue<pair<int, int>> q;
		q.push({0, 1}); // 1 - odd, 0 - even
		states[0] = 0;
		visited.insert(0);
		int n = nextVisit.size();
		int ret = 0;
		vector <int> last(n);
		last[0] = 1;
		set < pair <int, int> > done;
		done.insert({0, 1});
		for (lli day = 1; !q.empty(); day++) {

			day %= MOD;
			int sz = q.size();
			while (sz--) {
				pair<int, int> curr = q.front();
				q.pop();

				int node = curr.first;
				int occ = curr.second;
				int nxt;

				if (occ & 1) {
					nxt = nextVisit[node];
				} else {

					nxt = (node + 1) % n;
				}

				if (!done.count({nxt, 1})) {
					if (!states.count(nxt))states[nxt] = day;
					done.insert({nxt, 1});
					q.push({nxt, 1});
					visited.insert(nxt);

				} else if (!done.count({nxt, 0})) {
					if (!states.count(nxt))states[nxt] = day;
					q.push({nxt, 0});
					done.insert({nxt, 0});
					visited.insert(nxt);

				} else {


					int d = states[nxt];
					int diff = sub(sub(day, 1), d);
					// cout << diff << " " << nxt << "-- "<< st << endl;
					day = add((diff), day);
					if (!states.count(node))states[node] = day;
					q.push({node, (occ + 1) % 2});
					visited.insert(node);
					done.insert(q.front());

				}
				if (visited.size() == n) return day % MOD;
			}

		}
		return 0;
	}
};