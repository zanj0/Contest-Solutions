class Solution {
public:
	int minStoneSum(vector<int>& piles, int k) {
		priority_queue <int> pq(piles.begin(), piles.end());
		int ret = 0;
		while (!pq.empty() && k--) {
			int curr = pq.top();
			pq.pop();
			curr -= (curr / 2);
			if (curr > 0) pq.push(curr);
		}
		while (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
		return ret;
	}
};