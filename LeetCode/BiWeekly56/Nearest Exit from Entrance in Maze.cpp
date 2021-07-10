int directions[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
class Solution {
public:
	int row, col;
	bool isOutside(int x, int y) {
		return x < 0 || x >= row || y < 0 || y >= col;
	}
	vector < vector <int> > getDistanceFromEntrance(vector < vector <char> >& maze, vector <int> source) {
		vector < vector <int> > distance(row, vector <int>(col, INT_MAX));
		queue < pair <int, int> > q;
		q.push({source[0], source[1]});
		distance[source[0]][source[1]] = 0;
		while (!q.empty()) {
			pair <int, int> currPos = q.front();
			q.pop();
			int x = currPos.first;
			int y = currPos.second;
			for (int k = 0; k < 4; k++) {
				int nextX = x + directions[k][0];
				int nextY = y + directions[k][1];
				if (isOutside(nextX, nextY) || distance[nextX][nextY] != INT_MAX || maze[nextX][nextY] == '+')  continue;
				distance[nextX][nextY] = distance[x][y] + 1;
				q.push({nextX, nextY});
			}
		}
		distance[source[0]][source[1]] = INT_MAX;
		return distance;
	}
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		row = maze.size();
		col = row ? maze[0].size() : 0;
		vector < vector <int> > distance = getDistanceFromEntrance(maze, entrance);
		int ret = INT_MAX;
		for (int i = 0; i < col; i++) {
			ret = min({ret, distance[0][i], distance[row - 1][i]});
		}
		for (int i = 0; i < row; i++) {
			ret = min({ret, distance[i][0], distance[i][col - 1]});
		}
		if (ret == INT_MAX) ret = -1;
		return ret;
	}
};