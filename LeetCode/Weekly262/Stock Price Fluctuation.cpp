class StockPrice {
public:
	set<pair<int, int>> s; // {Data, TimeStamp}
	map<int, int> prev;
	int curr, timer;
	StockPrice() {

	}

	void update(int timestamp, int price) {
		if (timestamp >= timer) {
			timer = timestamp;
			curr = price;
		}

		s.erase({prev[timestamp], timestamp});

		s.insert({price, timestamp});
		prev[timestamp] = price;
	}

	int current() {
		return curr;
	}

	int maximum() {
		return s.rbegin()->first;
	}

	int minimum() {
		return s.begin()->first;
	}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */