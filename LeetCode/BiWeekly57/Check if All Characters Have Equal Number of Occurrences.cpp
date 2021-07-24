#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool areOccurrencesEqual(string s) {
		vector <int> countOfCharacters(26);
		int maxCountOfCharacters = 0;
		for (int i = 0; i < s.size(); i++) {
			countOfCharacters[s[i] - 'a']++;
			maxCountOfCharacters = max(maxCountOfCharacters, countOfCharacters[s[i] - 'a']);
		}
		for (int count : countOfCharacters) {
			if (count > 0 && count != maxCountOfCharacters) return false;
		}
		return true;
	}
};
int main() {
	Solution s = Solution();
	cout << s.areOccurrencesEqual("abacbc") << endl;
	cout << s.areOccurrencesEqual("aaabb") << endl;
}