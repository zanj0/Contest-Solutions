class Solution {
public:
	string reversePrefix(string word, char c) {
		int j = 0;
		int n = word.size();
		while (j < n && word[j] != c) {
			j++;
		}
		if (j == n) return word;
		int i = 0;
		while (i < j) {
			swap(word[i], word[j]);
			i++;
			j--;
		}
		return word;
	}
};