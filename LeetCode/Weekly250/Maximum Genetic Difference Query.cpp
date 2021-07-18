const int N = 1e5 + 6;
vector <int> graph[N];
vector <pair <int, int>> queries[N]; // {val, idx}
class Solution {
public:
	struct Node {
		Node* child[2];
		int cnt;
		Node() {
			cnt = 0;
			child[1] = child[0] = NULL;
		}
	};
	void deleteNode(int val, Node* head) {
		Node* curr = head;
		for (int i = 31; i >= 0; i--) {
			int bit = (val >> i) & 1;
			if (!curr->child[bit]) {
				curr->child[bit] = new Node();
			}
			curr = curr->child[bit];
			curr->cnt--;
		}
	}
	void insertNode(int val, Node* head) {
		Node* curr = head;
		for (int i = 31; i >= 0; i--) {
			int bit = (val >> i) & 1;
			if (!curr->child[bit]) {
				curr->child[bit] = new Node();
			}
			curr = curr->child[bit];
			curr->cnt++;
		}
	}
	int find(int val, Node* head) {
		Node* curr = head;
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			int bit = (val >> i) & 1;
			if (curr->child[!bit] && curr->child[!bit]->cnt > 0) {
				ans |= (1 << i);
				curr = curr->child[!bit];
			} else {
				curr = curr->child[bit];
			}

		}
		return ans;
	}
	void dfs(int node, int par, vector <int>& ret, Node* curr) {
		insertNode(node, curr);
		for (auto& it : queries[node]) {
			ret[it.second] = find(it.first, curr);
		}
		for (auto& it : graph[node]) {
			if (it == par) continue;
			dfs(it, node, ret, curr);
		}
		deleteNode(node, curr);
	}
	vector<int> maxGeneticDifference(vector<int>& par, vector<vector<int>>& q) {
		int n = par.size();
		for (int i = 0; i < n; i++) {
			graph[i].clear();
			queries[i].clear();
		}
		int root = -1;
		for (int i = 0; i < n; i++) {
			if (par[i] == -1) {
				root = i;
			} else {
				graph[i].push_back(par[i]);
				graph[par[i]].push_back(i);
			}
		}
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			queries[q[i][0]].push_back({q[i][1], i});
		}
		Node* curr = new Node();
		vector <int> ret(qsize);
		dfs(root, -1, ret, curr);
		return ret;
	}
};