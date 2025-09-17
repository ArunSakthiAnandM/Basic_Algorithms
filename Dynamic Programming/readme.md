# Dynamic Programming Algorithms

This folder contains implementations of classic dynamic programming algorithms in C++:

| Algorithm                        | Time Complexity (Best/Average/Worst) | Space Complexity |
| -------------------------------- | :----------------------------------: | :--------------: |
| Fibonacci Sequence               | O(n) (iterative), O(2^n) (recursive) |       O(n)       |
| Longest Common Subsequence (LCS) |                O(mn)                 |      O(mn)       |

## Algorithm Explanations & Use Cases

**Fibonacci Sequence:**
Computes Fibonacci numbers using dynamic programming (efficient) or recursion (simple but slow). Used in financial modeling and population growth predictions.

**Longest Common Subsequence (LCS):**
Finds the longest subsequence present in both strings using dynamic programming. Used in DNA analysis and file comparison tools.

Each algorithm file includes:

- C++ implementation
- Sample input and output in `main()`
- Console output for demonstration

## Usage

Compile and run any `.cpp` file to see the algorithm in action.

## Example

```
g++ fibonacci_sequence.cpp -o fibonacci && ./fibonacci
```
