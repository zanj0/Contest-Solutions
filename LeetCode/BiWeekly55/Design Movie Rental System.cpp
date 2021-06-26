const int N = 1e4 + 5;
class MovieRentingSystem {
public:
	struct CustomComparator {
		bool operator() (const vector <int>& a, const vector <int>& b) const {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] < b[i]) return true;
				else if (a[i] > b[i]) return false;
			}
			return false;
		}
	};
	unordered_map <int , unordered_map <int, int> > shopMovieToCost;
	vector < set  < vector <int>, CustomComparator> >  movieStatus; // Contains vector of {price, shop} for each movie.
	set < vector <int>, CustomComparator > rentedMovies; // Contains vector of {price, shop, movie}.
	MovieRentingSystem(int n, vector<vector<int>>& entries) {
		movieStatus.resize(N);
		int shop, movie, price;
		for (auto& it : entries) {
			shop = it[0];
			movie = it[1];
			price = it[2];
			movieStatus[movie].insert({price, shop});
			shopMovieToCost[shop][movie] = price;
		}
	}

	vector<int> search(int movie) {
		vector <int> ret;
		int cnt = min((int)movieStatus[movie].size(), 5);
		for (auto& it : movieStatus[movie]) {
			cnt--;
			ret.push_back(it[1]);
			if (cnt == 0) break;
		}
		return ret;
	}

	void rent(int shop, int movie) {
		int price = shopMovieToCost[shop][movie];
		rentedMovies.insert({price, shop, movie});
		movieStatus[movie].erase({price, shop});
	}

	void drop(int shop, int movie) {
		int price = shopMovieToCost[shop][movie];
		rentedMovies.erase({price, shop, movie});
		movieStatus[movie].insert({price, shop});

	}

	vector<vector<int>> report() {
		vector < vector <int> > ret;
		int cnt = min((int)rentedMovies.size(), 5);
		for (auto& it : rentedMovies) {
			cnt--;
			ret.push_back({it[1], it[2]});
			if (cnt == 0) break;
		}
		return ret;
	}
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */