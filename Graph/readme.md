# Graph Algorithms

This folder contains implementations of classic graph algorithms in C++:

| Algorithm      | Time Complexity (Best/Average/Worst) | Space Complexity |
| -------------- | :----------------------------------: | :--------------: |
| Bellman-Ford   |                O(VE)                 |       O(V)       |
| Dijkstra       |            O(E + V log V)            |       O(V)       |
| Floyd-Warshall |                O(V^3)                |      O(V^2)      |
| Kruskal        |              O(E log E)              |       O(V)       |
| Prim           |            O(E + V log V)            |       O(V)       |

## Algorithm Explanations & Use Cases

**Bellman-Ford:**
Finds shortest paths from a single source in a weighted graph, including negative weights. Used in network routing and currency exchange rate calculations.

**Dijkstra:**
Finds shortest paths from a single source in a graph with non-negative weights. Used in GPS navigation and network routing.

**Floyd-Warshall:**
Computes shortest paths between all pairs of vertices. Used in traffic analysis and transitive closure problems.

**Kruskal:**
Finds the minimum spanning tree using union-find. Used in network design and clustering.

**Prim:**
Finds the minimum spanning tree using a greedy approach. Used in network design and circuit layout.

Each algorithm file includes:

- C++ implementation
- Sample input and output in `main()`
- Console output for demonstration

## Usage

Compile and run any `.cpp` file to see the algorithm in action.

## Example

```
g++ dijkstra.cpp -o dijkstra && ./dijkstra
```
