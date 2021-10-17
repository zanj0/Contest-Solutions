typedef long long ll;
class Bank {
public:
	vector<ll> v;
	Bank(vector<long long>& balance) {
		v = balance;
	}
	bool outside(int x) {
		return x >= v.size() || x < 0;
	}
	bool transfer(int account1, int account2, long long money) {
		account1--;
		account2--;
		if (outside(account1) || outside(account2)) return false;
		if (v[account1] < money) return false;
		v[account1] -= money;
		v[account2] += money;
		return true;
	}

	bool deposit(int account, long long money) {
		account--;
		if (outside(account)) return false;
		v[account] += money;
		return true;
	}

	bool withdraw(int account, long long money) {
		account--;
		if (outside(account)) return false;
		if (v[account] < money) return false;
		v[account] -= money;
		return true;
	}
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */