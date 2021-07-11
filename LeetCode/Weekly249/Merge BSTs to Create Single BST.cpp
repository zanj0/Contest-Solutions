/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int N = 5e4 + 5;
int sizeOfTree[N];
unordered_map <int, int> leaveCnt;
unordered_set <int> visited;
unordered_map <int, TreeNode*> roots;
class Solution {
public:
	int n;
	bool bad;
	set <int> all;
	void getLeaves(TreeNode* node, int idx) {
		if (!node) return;
		all.insert(node->val);
		if (!node->left && !node->right) leaveCnt[node->val]++;
		sizeOfTree[idx]++;
		getLeaves(node->left, idx);
		getLeaves(node->right, idx);
	}
	void pre() {
		for (int i = 0; i < n; i++) sizeOfTree[i] = 0;
		leaveCnt.clear();
		visited.clear();
		roots.clear();
		bad = false;
		all.clear();
	}

	TreeNode* dfs(TreeNode* node, int low, int high) {
		if (!node) return NULL;
		all.erase(node->val);
		if (node->val <= low || node->val >= high) {
			bad = true;
			return NULL;
		}
		if (!node->left && !node->right) {
			if ((roots.count(node->val) && !visited.count(node->val))) {
				visited.insert(node->val);
				node = roots[node->val];
				node->left = dfs(node->left, low, node->val);
				node->right = dfs(node->right, node->val, high);
			} else if (roots.count(node->val)) {
				bad = true;
				return NULL;
			}
		} else {
			node->left = dfs(node->left, low, node->val);
			node->right = dfs(node->right, node->val, high);
		}
		return node;
	}
	TreeNode* canMerge(vector<TreeNode*>& trees) {
		n = trees.size();
		pre();
		TreeNode* root = NULL;
		set <int> leaves;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			getLeaves(trees[i], i);
			roots[trees[i]->val] = trees[i];
		}
		int possibleRoots = 0;
		for (int i = 0; i < n; i++) {
			if (sizeOfTree[i] == 1 && leaveCnt[trees[i]->val] == 1) {
				possibleRoots++;
				root = trees[i];
			} else if (sizeOfTree[i] > 1 && leaveCnt[trees[i]->val] == 0) {
				possibleRoots++;
				root = trees[i];
			}
		}

		if (possibleRoots != 1) return NULL;
		root = dfs(root, INT_MIN, INT_MAX);
		if (bad || !all.empty()) return NULL;
		return root;
	}
};