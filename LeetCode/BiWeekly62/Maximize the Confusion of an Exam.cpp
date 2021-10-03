class Solution {
public:
    int calc(string& s, char req, int k) {
        int ret = 0;
        int i = 0;
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] != req)cnt++;
            while (cnt > k) {
                if (s[i] != req) cnt--;
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
    int maxConsecutiveAnswers(string ans, int k) {
        int f = calc(ans, 'F', k)   ;
        int t = calc(ans, 'T', k);
        return max(f, t);
    }
};