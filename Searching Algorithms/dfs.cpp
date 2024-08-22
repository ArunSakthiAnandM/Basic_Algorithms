#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t); 
    adj[t].push_back(s);
}

void DFS(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
        if (visited[i] == false)
            DFS(adj, visited, i);
}

int main(){
    int V = 5;
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};

    vector<vector<int>> adj(V);
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
    
    vector<bool> visited(V, false);
    
    int starting_node = 0;
    DFS(adj, visited, starting_node);
    
    return 0;
}