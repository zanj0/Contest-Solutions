class Solution {
public:
	int finalValueAfterOperations(vector<string>& operations) {
		int ret = 0;
		for (auto& it : operations) {
			if (it == "++X" || it == "X++") ret++;
			else ret--;
		}
		return ret;
	}
};