typedef long long int lli;
class Solution {
public:
	long long wonderfulSubstrings(string word) {
		lli n = word.size();
		lli ret = 0;
		unordered_map <lli, lli> cnt;
		lli mask = 0;
		cnt[mask] = 1;
		for (int i = 0; i < n; i++) {
			mask ^= (1l << (word[i] - 'a')); // Current substring configuration [0..i]
			for (int j = 0; j < 26; j++) {
				lli tmp = (1l << j); // 1 odd characters.
				lli req = (tmp ^ mask);
				ret += cnt.count(req) ? cnt[req] : 0;
			}
			ret += cnt[mask]; // No odd characters.
			cnt[mask]++;
		}
		return ret;
	}
};