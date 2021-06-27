class Solution {
public:
	void out(vector <int>& v) {
		for (auto& it : v) {
			cout << it << " ";
		}
		cout << endl;
	}
	vector <int> make1D(int startRow, int endRow, int startCol, int endCol, vector < vector <int> >& grid) {
		vector <int> ret;
		for (int i = startCol; i <= endCol; i++) {
			ret.push_back(grid[startRow][i]);
		}
		for (int i = startRow + 1; i <= endRow; i++) {
			ret.push_back(grid[i][endCol]);
		}
		for (int i = endCol - 1; i >= startCol; i--) {
			ret.push_back(grid[endRow][i]);
		}
		for (int i = endRow - 1; i >= startRow + 1; i--) {
			ret.push_back(grid[i][startCol]);
		}
		return ret;
	}
	void fillGrid(int startRow, int endRow, int startCol, int endCol, vector < vector <int> >& grid, vector <int>& numbersIn1D, int k) {
		vector <int> arr;
		int n = numbersIn1D.size();
		for (int i = k; i < n; i++) {
			arr.push_back(numbersIn1D[i]);
		}
		for (int i = 0; i < k; i++) {
			arr.push_back(numbersIn1D[i]);
		}
		int j = 0;
		for (int i = startCol; i <= endCol; i++) {
			grid[startRow][i] = arr[j];
			j++;
		}
		for (int i = startRow + 1; i <= endRow; i++) {
			grid[i][endCol] = arr[j];
			j++;
		}
		for (int i = endCol - 1; i >= startCol; i--) {
			grid[endRow][i] = arr[j];
			j++;
		}
		for (int i = endRow - 1; i >= startRow + 1; i--) {
			grid[i][startCol] = arr[j];
			j++;
		}

	}
	vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
		int r = grid.size();
		int c = r ? grid[0].size() : 0;
		int startRow = 0;
		int endRow = r - 1;
		int startCol = 0;
		int endCol = c - 1;
		while (startRow < endRow && startCol < endCol) {
			int countOfNumbers = 2 * (endRow - startRow + 1) + 2 * (endCol - startCol + 1) - 4;
			int newK = k % countOfNumbers;
			vector <int> numbersIn1D = make1D(startRow, endRow, startCol, endCol, grid);
			fillGrid(startRow, endRow, startCol, endCol, grid, numbersIn1D, newK);
			startRow++;
			endRow--;
			startCol++;
			endCol--;
		}
		return grid;
	}
};