#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int smallestChair(vector<vector<int>>& times, int targetFriend) {
		int ret = 0;
		int n = times.size();
		set <int> available;
		for (int i = 0; i < n; i++) available.insert(i);
		vector < vector <int> > events; // {time, seat alloted / seat removed}
		for (int i = 0; i < n; i++) {
			events.push_back({times[i][0], 1, i}); // Entered.
			events.push_back({times[i][1], -1, i}); // Left.
		}
		sort(events.begin(), events.end());
		vector <int> seatAssigned(n);
		int seatNumber;
		for (int i = 0; i < events.size(); i++) {
			if (events[i][1] == 1) {
				seatNumber = *(available.begin());
				seatAssigned[events[i].back()] = seatNumber;
				available.erase(seatNumber);
				if (events[i].back() == targetFriend) return seatNumber;
			} else {
				seatNumber = seatAssigned[events[i].back()];
				available.insert(seatNumber);
			}
		}

		return seatAssigned[targetFriend];
	}
};
int main() {
	freopen("output.txt", "w", stdout);
	Solution s = Solution();
	// cout << s.smallestChair({{1, 4}, {2, 3}, {4, 6}}, 1) << endl;
	cout << s.smallestChair({{3, 100000}, {37, 100000}, {34, 100000}, {16, 100000}, {28, 100000}, {19, 100000}, {14, 100000}, {29, 100000}, {5, 100000}, {9, 100000}, {25, 100000}, {18, 100000}, {31, 100000}, {17, 100000}, {12, 100000}, {36, 100000}, {30, 100000}, {13, 100000}, {27, 100000}, {10, 100000}, {21, 100000}, {38, 100000}, {11, 100000}, {46, 100000}, {2, 100000}, {33, 100000}, {20, 100000}, {8, 100000}, {35, 100000}, {43, 100000}, {23, 100000}, {22, 100000}, {15, 100000}, {44, 100000}, {45, 100000}, {7, 100000}, {24, 100000}, {42, 100000}, {6, 100000}, {1, 100000}, {26, 100000}, {39, 100000}, {32, 100000}, {40, 100000}, {41, 100000}, {4, 100000}},
	23) << endl;
}