class Solution {
public:
    vector<int> getSmallestKLengthSubsequence(string& s, int k, char req, int l) {
        vector<int> ret;
        int n = s.size();
        int cnt = 0;
        int has = 0;
        for (auto& it : s) {
            if (it == req) cnt++;
        }
        for (int i = 0; i < n; i++) {
            while (!ret.empty() && s[ret.back()] > s[i] && (ret.size() + n - 1 - i) >= k) {
                if (s[ret.back()] == req) {
                    if (has - 1 + cnt >= l) {
                        has--;
                        ret.pop_back();
                    } else break;
                } else
                    ret.pop_back();
            }
            while (max(k - (int)ret.size(), 0) < max(l - has, 0)) ret.pop_back();
            if (s[i] == req) {
                has++;
                cnt--;
            }
            ret.push_back(i);
        }
        while (ret.size() > k) {
            ret.pop_back();
        }
        return ret;
    }
    void out(vector<int>& v) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        vector<int> has = getSmallestKLengthSubsequence(s, k, letter, repetition);
        string ret = "";
        for (int i : has) {
            ret += s[i];
        }
        return ret;
    }
};