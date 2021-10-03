class Solution {
public:
    string getSuffix(string& s, string& t) {
        string ret = "";
        int k = 0;
        for (int i = 0; i < t.size(); i++) {
            if (k < s.size()) {
                if (s[k] == t[i])k++;
                else return "";
            } else {
                ret += t[i];
            }
        }
        return ret;
    }
    string getPrefix(string& s, string& t) {
        string ret = "";
        int k = s.size() - 1;
        for (int i = t.size() - 1; i >= 0; i--) {
            if (k >= 0) {
                if (s[k] == t[i])k--;
                else return "";
            } else {
                ret += t[i];
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int ret = 0;
        map<string, int> cnt;
        for (auto& it : nums) cnt[it]++;
        for (int i = 0; i < n; i++) {
            string req = "";
            int k = 0;
            string pre = getPrefix(nums[i], target);
            string suff = getSuffix(nums[i], target);
            // cout << nums[i] << " -- " << suff << " -- " << pre << endl;
            if (cnt.count(pre)) {
                ret += cnt[pre];
                if (pre == nums[i]) ret--;
            }
            if (cnt.count(suff)) {
                ret += cnt[suff];
                if (suff == nums[i]) ret--;
            }
            // cout << ret << " " << i << endl;

        }
        return ret / 2;
    }
};