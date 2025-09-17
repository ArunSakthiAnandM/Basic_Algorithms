 #include <bits/stdc++.h>
 using namespace std;

void prim(vector<vector<pair<int, int>>>& adj, int V) {
	vector<int> key(V, INT_MAX), parent(V, -1);
	vector<bool> inMST(V, false);
	key[0] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = -1;
		for (int v = 0; v < V; v++)
			if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;
		inMST[u] = true;
		for (auto& edge : adj[u]) {
			int v = edge.first, w = edge.second;
			if (!inMST[v] && w < key[v]) {
				key[v] = w;
				parent[v] = u;
			}
		}
	}
	cout << "Edges in MST:\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << endl;
}

int main() {
	int V = 5;
	vector<vector<pair<int, int>>> adj(V);
	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});
	prim(adj, V);
	return 0;
}
