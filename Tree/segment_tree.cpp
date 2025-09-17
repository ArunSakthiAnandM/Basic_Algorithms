 #include <bits/stdc++.h>
 using namespace std;

class SegmentTree {
	vector<int> tree, arr;
	int n;
public:
	SegmentTree(const vector<int>& input) {
		arr = input;
		n = arr.size();
		tree.resize(4 * n);
		build(1, 0, n - 1);
	}
	void build(int node, int l, int r) {
		if (l == r) tree[node] = arr[l];
		else {
			int mid = (l + r) / 2;
			build(2 * node, l, mid);
			build(2 * node + 1, mid + 1, r);
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}
	void update(int node, int l, int r, int idx, int val) {
		if (l == r) tree[node] = val;
		else {
			int mid = (l + r) / 2;
			if (idx <= mid) update(2 * node, l, mid, idx, val);
			else update(2 * node + 1, mid + 1, r, idx, val);
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}
	int query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int mid = (l + r) / 2;
		return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
	}
};

int main() {
	vector<int> arr = {1, 3, 5, 7, 9, 11};
	SegmentTree st(arr);
	cout << "Sum of values in range [1, 3]: " << st.query(1, 0, arr.size() - 1, 1, 3) << endl;
	st.update(1, 0, arr.size() - 1, 1, 10); // arr[1] = 10
	cout << "Sum of values in range [1, 3] after update: " << st.query(1, 0, arr.size() - 1, 1, 3) << endl;
	return 0;
}
