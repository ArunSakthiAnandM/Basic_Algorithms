 #include <bits/stdc++.h>
 using namespace std;

struct Edge {
	int src, dest, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = edges[j].src;
			int v = edges[j].dest;
			int w = edges[j].weight;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}
	for (int j = 0; j < E; j++) {
		int u = edges[j].src;
		int v = edges[j].dest;
		int w = edges[j].weight;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			cout << "Graph contains negative weight cycle\n";
			return;
		}
	}
	cout << "Vertex Distance from Source " << src << ":\n";
	for (int i = 0; i < V; i++)
		cout << i << ": " << dist[i] << "\n";
}

int main() {
	int V = 5, E = 8;
	vector<Edge> edges = {
		{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
		{1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
	};
	bellmanFord(edges, V, E, 0);
	return 0;
}
