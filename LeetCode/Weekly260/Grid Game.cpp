typedef long long int lli;
class Solution {
public:


    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<lli> pref(n), suff(n);
        for (int i = 0; i < n; i++) {
            pref[i] = grid[1][i];
            if (i)pref[i] += pref[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = grid[0][i];
            if (i + 1 < n)suff[i] += suff[i + 1];
        }
        lli ret = 1e18;
        for (int i = 0; i < n; i++) {
            lli op1 = i - 1 >= 0 ? pref[i - 1] : 0;
            lli op2 = i + 1 < n ? suff[i + 1] : 0;
            // cout << i << " " << op1 << " " << op2 << endl;
            ret = min(ret, max(op1, op2));
        }
        return ret;
    }
};