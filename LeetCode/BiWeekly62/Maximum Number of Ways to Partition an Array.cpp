typedef long long int lli;
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        lli ret = 0;
        lli n = nums.size();
        vector<lli> pre(n), suff(n);
        for (lli i = 0; i < n; i++) {
            pre[i] = nums[i];
            if (i) pre[i] += pre[i - 1];
        }
        for (lli i = n - 1; i >= 0; i--) {
            suff[i] = nums[i];
            if (i + 1 < n) suff[i] += suff[i + 1];
        }
        map<lli, lli> right, left;
        for (lli i = 0; i < n - 1; i++) {
            right[pre[i] - suff[i + 1]]++;
        }
        if (right.count(0)) ret = right[0];
        lli diff, curr;
        for (lli i = 0; i < n; i++) {
            curr = 0;
            diff = k - nums[i];
            if (right.count(-diff)) {
                curr += right[-diff];
            }
            if (left.count(diff)) {
                curr += left[diff];
            }
            ret = max(ret, curr);
            if (i + 1 < n) {
                lli tempDiff = pre[i] - suff[i + 1];
                right[tempDiff]--;
                left[tempDiff]++;
                if (right[tempDiff] == 0) right.erase(tempDiff);
            }

        }
        return ret;
    }
};