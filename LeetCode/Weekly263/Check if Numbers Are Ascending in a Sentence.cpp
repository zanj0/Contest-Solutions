class Solution {
public:
	vector <string> split(string& s, char delimiter) {
		// cout << s << endl;
		vector <string> tokens;
		string token;
		istringstream tokenStream(s);
		while (getline(tokenStream, token, delimiter)) {
			tokens.push_back(token);
		}
		return tokens;
	}
	bool areNumbersAscending(string s) {
		vector<string> s2 = split(s, ' ');
		int last = -1;
		for (auto& it : s2) {
			if (it[0] >= '0' && it[0] <= '9') {
				if (last >= stoi(it)) {
					return false;
				}
				last = stoi(it);
			}
		}
		return true;
	}
};