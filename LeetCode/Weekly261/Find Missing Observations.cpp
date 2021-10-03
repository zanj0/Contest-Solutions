class Solution {
public:
    int ceilDiv(int a, int b) {
        return (a + b - 1) / b;
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int reqSum = (mean * (m + n)) - sum;
        int per = ceilDiv(reqSum, n);
        vector<int> ret;
        if (per > 6) return ret;
        ret = vector<int>(n, 1);
        reqSum -= n;
        if (reqSum < 0) return {};
        for (int i = 0; i < ret.size(); i++) {
            int add = min(reqSum, 5);
            ret[i] += add;
            reqSum -= add;
        }
        return ret;

    }
};