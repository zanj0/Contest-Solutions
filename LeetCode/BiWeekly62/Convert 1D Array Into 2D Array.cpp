class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& v, int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n));
        int s = v.size();
        if (n * m != s) return {};
        int r = 0, c = 0;
        for (int i = 0; i < s; i++) {
            if (c == n) {
                c = 0;
                r++;
            }
            ret[r][c] = v[i];
            c++;
        }
        return ret;
    }
};