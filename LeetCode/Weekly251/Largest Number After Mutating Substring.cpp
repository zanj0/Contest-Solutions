class Solution {
public:
	string maximumNumber(string num, vector<int>& change) {
		bool changing = false;
		for (int i = 0; i < num.size(); i++) {
			if (num[i] - '0' < change[num[i] - '0']) {
				num[i] = (char)(change[num[i] - '0'] + '0');
				changing = true;
			} else if (changing && num[i] - '0' > change[num[i] - '0']) break;
		}
		return num;
	}
};