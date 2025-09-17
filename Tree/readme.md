# Tree Algorithms

This folder contains implementations of fundamental tree algorithms in C++:

| Algorithm          | Time Complexity (Best/Average/Worst) | Space Complexity |
| ------------------ | :----------------------------------: | :--------------: |
| AVL Tree           |  O(log n) for insert/search/delete   |       O(n)       |
| Binary Search Tree |    O(log n) (best), O(n) (worst)     |       O(n)       |
| Fenwick Tree       |      O(log n) for update/query       |       O(n)       |
| Segment Tree       |      O(log n) for update/query       |       O(n)       |

## Algorithm Explanations & Use Cases

**AVL Tree:**
Self-balancing binary search tree that maintains O(log n) height for fast insert, search, and delete. Used in databases and file systems for indexing.

**Binary Search Tree (BST):**
Stores elements in a sorted manner for fast search, insert, and delete. Used in symbol tables and dynamic sets.

**Fenwick Tree (Binary Indexed Tree):**
Efficiently computes prefix sums and updates in logarithmic time. Used in competitive programming for range queries.

**Segment Tree:**
Supports efficient range queries and updates on arrays. Used in image processing and range query problems.

Each algorithm file includes:

- C++ implementation
- Sample input and output in `main()`
- Console output for demonstration

## Usage

Compile and run any `.cpp` file to see the algorithm in action.

## Example

```
g++ avl_tree.cpp -o avl_tree && ./avl_tree
```
