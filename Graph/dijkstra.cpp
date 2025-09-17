 #include <bits/stdc++.h>
 using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
	int V = adj.size();
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto& edge : adj[u]) {
			int v = edge.first, w = edge.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	cout << "Vertex Distance from Source " << src << ":\n";
	for (int i = 0; i < V; i++)
		cout << i << ": " << dist[i] << "\n";
}

int main() {
	int V = 5;
	vector<vector<pair<int, int>>> adj(V);
	adj[0].push_back({1, 10});
	adj[0].push_back({4, 5});
	adj[1].push_back({2, 1});
	adj[1].push_back({4, 2});
	adj[2].push_back({3, 4});
	adj[3].push_back({0, 7});
	adj[3].push_back({2, 6});
	adj[4].push_back({1, 3});
	adj[4].push_back({2, 9});
	adj[4].push_back({3, 2});
	dijkstra(adj, 0);
	return 0;
}
