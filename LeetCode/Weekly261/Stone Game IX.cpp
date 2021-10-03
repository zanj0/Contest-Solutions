class Solution {
public:
    bool firstWin(int val, map<int, int> cnt) {
        if (!cnt.count(val)) return false;
        bool first = true;
        int sum = 0;
        sum += val;
        cnt[val]--;
        first = false;
        while (1) {
            bool done = false;
            for (auto& it : cnt) {
                if (it.second > 0 && (sum + it.first) % 3) {
                    sum += it.first;
                    sum %= 3;
                    done = true;
                    it.second--;
                    break;
                }
            }
            if (done) first = !first;
            else {
                if (!first) {
                    for (auto& it : cnt) {
                        if (it.second > 0) return true;
                    }
                    return false;
                }
                return !first;
            }

        }

        return false;
    }
    bool stoneGameIX(vector<int>& stones) {
        map<int, int> cnt;
        int sum = 0;
        for (int i : stones) {
            cnt[(i % 3)]++;
            sum += i;
            sum %= 3;
        }
        bool ret = false;
        for (int i = 1; i <= 2; i++) {
            ret = ret || firstWin(i, cnt);
        }
        return ret;

    }
};