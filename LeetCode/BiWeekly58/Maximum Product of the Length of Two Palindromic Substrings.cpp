typedef long long int lli;
class Solution {
public:
	vector<lli> manachar(string s)
	{
		int n = s.size();
		s = "@" + s + "$";
		vector<lli> len(n + 1);
		lli l = 1, r = 1;
		for (int i = 1; i <= n; i++)
		{
			len[i] = min(r - i, len[l + (r - i)]);
			while (s[i - len[i]] == s[i + len[i]])
				len[i]++;
			if (i + len[i] > r)
			{
				l = i - len[i];
				r = i + len[i];
			}
		}
		len.erase(begin(len));
		return len;
	}
	long long maxProduct(string s) {
		lli n = s.size();
		lli ret = 0;
		lli maxVal = 0;
		vector <lli> maxLenAroundCentre = manachar(s);
		vector <lli> left(n), right(n);
		for (int i = 0; i < maxLenAroundCentre.size(); i++) {
			lli rightIdx = i + maxLenAroundCentre[i] - 1;
			lli leftIdx = i - (maxLenAroundCentre[i] - 1);
			left[rightIdx] = max(left[rightIdx], 2 * maxLenAroundCentre[i] - 1);
			right[leftIdx] = max(right[leftIdx], 2 * maxLenAroundCentre[i] - 1);
		}
		for (int i = n - 2; i >= 0; i--) {
			left[i] = max(left[i], left[i + 1] - 2);
		}
		for (int i = 1; i < n; i++) {
			right[i] = max(right[i], right[i - 1] - 2);
		}

		for (int i = 0; i < n - 1; i++) {
			maxVal = max(maxVal, left[i]);
			ret = max(ret, maxVal * right[i + 1]);
		}
		return ret;
	}
};