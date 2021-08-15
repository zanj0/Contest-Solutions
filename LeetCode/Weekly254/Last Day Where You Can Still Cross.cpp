int dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
	int r, c;
	bool ok(set <pair <int, int>>& cells) {
		queue <pair <int, int>> q;
		set <pair <int, int>> visited;
		for (int i = 1; i <= c; i++) {

			if (!cells.count({1, i})) {
				q.push({1, i});
				visited.insert({1, i});
			}
		}
		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();
			if (curr.first == r) return true;
			for (int k = 0; k < 4; k++) {
				int nx = curr.first + dir[k][0];
				int ny = curr.second + dir[k][1];
				if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
				if (!visited.count({nx, ny}) && !cells.count({nx, ny})) {
					visited.insert({nx, ny});
					q.push({nx, ny});
				}
			}
		}
		return false;
	}
	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
		int ret = 0;
		r = row;
		c = col;
		int low = 0;
		int high = (int)cells.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			set<pair<int, int>> bad;
			for (int i = 0; i <= mid; i++) {
				bad.insert({cells[i][0], cells[i][1]});
			}
			if (ok(bad)) {
				ret = mid + 1;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return ret;
	}
};