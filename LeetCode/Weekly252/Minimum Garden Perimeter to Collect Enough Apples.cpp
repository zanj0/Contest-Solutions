typedef long long int lli;
class Solution {
public:
	lli f(lli x) {
		return (x * (x + 1)) / 2;
	}
	lli getRange(lli l, lli r) {
		return f(r) - f(l);
	}
	lli getValueOfLen(int len) {
		lli lastVal = (len + 1) + (len - 1);
		lli start = len;
		lli ret = (start * 4) + (lastVal * 4);
		lli between = getRange(start, lastVal - 1) * 8;
		return ret + between;
	}
	long long minimumPerimeter(long long neededApples) {
		lli ret = 1;
		lli sum = 0;
		lli len = 0;
		while (sum < neededApples) {
			len++;
			sum += getValueOfLen(len);
		}
		return len * (lli)2 * (lli)4;
	}
};