class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& v) {
		int n = v.size();
		vector <int> ret(n);
		stack <int> st;
		for (int i = n - 1; i >= 0; i--) {
			ret[i] = (int)st.size();
			while (!st.empty() && v[i] > v[st.top()]) st.pop();
			if (!st.empty()) ret[i] -= ((int)st.size() - 1);
			st.push(i);
		}
		return ret;
	}
};