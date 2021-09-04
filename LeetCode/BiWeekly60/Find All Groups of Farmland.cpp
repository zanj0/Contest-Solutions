int dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
	int r, c;
	bool inside(int i, int j) {
		return i >= 0 && i < r && j >= 0 && j < c;
	}
	void dfs(int i, int j, vector<vector<int>>& mat, vector<int>& last) {
		if (!inside(i, j) || !mat[i][j]) return;
		last[0] = max(last[0], i);
		last[1] = max(last[1], j);
		mat[i][j] = 0;
		for (int k = 0; k < 4; k++) {
			dfs(i + dir[k][0], j + dir[k][1], mat, last);
		}
	}
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		vector<vector<int>> ret;
		r = land.size();
		c = land[0].size();
		for (int j = 0; j < c; j++) {
			for (int i = 0; i < r; i++) {
				if (land[i][j]) {
					vector<int> temp{i, j};
					ret.push_back(temp);
					dfs(i, j, land, temp);
					ret.back().push_back(temp[0]);
					ret.back().push_back(temp[1]);
				}
			}
		}
		return ret;
	}
};