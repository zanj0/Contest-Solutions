struct Node {
	string value;
	map <string, Node*> children;
	bool del;
	Node(const string& s) {
		value = s;
		del = false;
	}
};
class Solution {
public:
	void addPath(Node* root, vector <string>& path) {
		Node* curr = root;
		for (auto& it : path) {
			if (!curr->children[it]) curr->children[it] = new Node(it);
			curr = curr->children[it];
		}
	}
	map <string, Node*> visited;
	string trim(Node* node) {
		string subtree = "";
		for (auto& it : node->children) {
			subtree += trim(it.second);
		}
		if (subtree.size()) {
			if (visited.count(subtree)) {
				visited[subtree]->del = node->del = true;
			} else {
				visited[subtree] = node;
			}
		}
		return "(" + node->value + subtree + ")";
	}
	vector < vector <string> > ret;
	void getPath(Node* node, vector <string> path) {
		if (node->del) return;
		if (!path.empty()) ret.push_back(path);
		for (auto& it : node->children) {
			path.push_back(it.first);
			getPath(it.second, path);
			path.pop_back();
		}
	}
	vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
		Node* root = new Node("");
		for (auto& it : paths) addPath(root, it);
		vector <string> path;
		trim(root);
		getPath(root, path);
		return ret;
	}
};