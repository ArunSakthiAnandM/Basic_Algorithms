# Searching Algorithms

This folder contains implementations of classic searching algorithms in C++:

| Algorithm     | Time Complexity (Best/Average/Worst) | Space Complexity |
| ------------- | :----------------------------------: | :--------------: |
| BFS           |               O(V + E)               |       O(V)       |
| DFS           |               O(V + E)               |       O(V)       |
| Binary Search |        O(1)/O(log n)/O(log n)        |       O(1)       |

## Algorithm Explanations & Use Cases

**Breadth-First Search (BFS):**
Traverses a graph level by level using a queue. Used in social networks to find shortest paths and in web crawlers.

**Depth-First Search (DFS):**
Explores a graph by going as deep as possible before backtracking. Used in maze solving, topological sorting, and cycle detection.

**Binary Search:**
Efficiently finds an element in a sorted array by repeatedly dividing the search interval in half. Used in database indexing and search engines.

Each algorithm file includes:

- C++ implementation
- Sample input and output in `main()`
- Console output for demonstration

## Usage

Compile and run any `.cpp` file to see the algorithm in action.

## Example

```
g++ bfs.cpp -o bfs && ./bfs
```
