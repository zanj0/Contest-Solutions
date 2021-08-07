int dir[8][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};
class Solution {
public:
	int r, c;
	vector < vector <char> > board;
	int colourCnt[2];
	bool inside(int i, int j) {
		return i >= 0 && i < r && j >= 0 && j < c;
	}
	int getColour(char c) {
		return c == 'W' ? 0 : 1;
	}
	bool dfs(int i, int j, int k, int startColour) {
		if (!inside(i, j) || board[i][j] == '.') return colourCnt[0] + colourCnt[1] >= 3 && colourCnt[startColour] == 2;
		int currColour = getColour(board[i][j]);
		if (currColour != startColour ) {
			if (colourCnt[startColour] != 1) return false;
		}
		colourCnt[currColour]++;
		if (colourCnt[startColour] == 2 && colourCnt[!startColour]) return true;
		return dfs(i + dir[k][0], j + dir[k][1], k, startColour);
	}
	bool checkMove(vector<vector<char>>& b, int rMove, int cMove, char colour) {
		board = b;
		r = board.size();
		c = board[0].size();
		board[rMove][cMove] = colour;
		for (int k = 0; k < 8; k++) {
			colourCnt[0] = colourCnt[1] = 0;
			if (dfs(rMove, cMove, k, getColour(colour))) return true;
		}
		return false;
	}
};