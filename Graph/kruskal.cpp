 #include <bits/stdc++.h>
 using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(const Edge& other) const { return w < other.w; }
};

struct DSU {
	vector<int> parent, rank;
	DSU(int n) : parent(n), rank(n, 0) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}
	void unite(int x, int y) {
		int xr = find(x), yr = find(y);
		if (xr == yr) return;
		if (rank[xr] < rank[yr]) parent[xr] = yr;
		else if (rank[xr] > rank[yr]) parent[yr] = xr;
		else { parent[yr] = xr; rank[xr]++; }
	}
};

void kruskal(int V, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());
	DSU dsu(V);
	vector<Edge> mst;
	for (auto& e : edges) {
		if (dsu.find(e.u) != dsu.find(e.v)) {
			mst.push_back(e);
			dsu.unite(e.u, e.v);
		}
	}
	cout << "Edges in MST:\n";
	for (auto& e : mst)
		cout << e.u << " - " << e.v << " : " << e.w << endl;
}

int main() {
	int V = 4;
	vector<Edge> edges = {
		{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
	};
	kruskal(V, edges);
	return 0;
}
