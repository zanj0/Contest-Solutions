class Solution {
public:
    int minimumMoves(string s) {
        int i = 0;
        int n = s.size();
        int ret = 0;
        while (i < n) {
            if (s[i] == 'X') {
                ret++;
                i += 3;
            } else {
                i++;
            }
        }
        return ret;
    }
};