 #include <bits/stdc++.h>
 using namespace std;

class FenwickTree {
	vector<int> BIT;
	int n;
public:
	FenwickTree(int size) : n(size) {
		BIT.assign(n + 1, 0);
	}
	void update(int idx, int val) {
		for (++idx; idx <= n; idx += idx & -idx)
			BIT[idx] += val;
	}
	int query(int idx) {
		int sum = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			sum += BIT[idx];
		return sum;
	}
};

int main() {
	vector<int> arr = {1, 7, 3, 0, 7, 8, 3, 2, 6, 2};
	int n = arr.size();
	FenwickTree ft(n);
	for (int i = 0; i < n; i++) ft.update(i, arr[i]);
	cout << "Prefix sum up to index 5: " << ft.query(5) << endl;
	ft.update(3, 6); // arr[3] += 6
	cout << "Prefix sum up to index 5 after update: " << ft.query(5) << endl;
	return 0;
}
