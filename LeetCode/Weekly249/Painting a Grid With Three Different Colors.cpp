// 2 bits for a single colour
typedef long long int lli;
const lli MOD = 1e9 + 7;
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
int dp[1 << 10][1005];
class Solution {
public:
	int row, col;
	int getColour(int mask, int pos) {
		return (mask >> (2 * pos)) & 3;
	}
	int setColour(int mask, int colour, int pos) {
		mask |= (colour << (2 * pos));
		return mask;
	}
	void getNextState(int idx, int prevMask, vector <int>& nxtStates, int currMask) {
		if (idx == row) {
			nxtStates.push_back(currMask);
			return;
		}
		for (int currColour = 1; currColour <= 3; currColour++) {
			int prevColColour = prevMask != -1 ? getColour(prevMask, idx) : -1;
			int prevRowColour = idx - 1 >= 0 ? getColour(currMask, idx - 1) : -1;
			if (prevColColour != currColour && prevRowColour != currColour) {
				getNextState(idx + 1, prevMask, nxtStates, setColour(currMask, currColour, idx));
			}
		}
	}
	int dfs(int mask, int idx) {
		if (idx == col) return 1;
		if (mask != -1 && dp[mask][idx] != -1) return dp[mask][idx];
		vector <int> nxtStates;
		getNextState(0, mask, nxtStates, 0);
		int ret = 0;
		for (auto& nxtState : nxtStates) {
			ret = add(ret, dfs(nxtState, idx + 1));
		}
		if (mask == -1) return ret;
		return dp[mask][idx] = ret;
	}
	int colorTheGrid(int m, int n) {
		row = m;
		col = n;
		int ret = 0;
		memset(dp, -1, sizeof dp);
		ret = dfs(-1, 0);
		return ret;
	}
};