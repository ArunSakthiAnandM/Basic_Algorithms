# String Algorithms

This folder contains implementations of classic string algorithms in C++:

| Algorithm                     | Time Complexity (Best/Average/Worst) | Space Complexity |
| ----------------------------- | :----------------------------------: | :--------------: |
| KMP (Knuth-Morris-Pratt)      |               O(n + m)               |       O(m)       |
| Boyer-Moore                   |     O(n/m) (best), O(nm) (worst)     |       O(m)       |
| Rabin-Karp                    |  O(n + m) (average), O(nm) (worst)   |       O(1)       |
| Longest Palindromic Substring |                O(n^2)                |      O(n^2)      |

## Algorithm Explanations & Use Cases

**KMP (Knuth-Morris-Pratt):**
Efficiently searches for a pattern in a text by precomputing a prefix table to avoid redundant comparisons. Used in DNA sequence analysis and plagiarism detection.

**Boyer-Moore:**
Searches for a pattern in a text by skipping sections using bad character and good suffix heuristics. Used in text editors and search engines for fast searching.

**Rabin-Karp:**
Uses hashing to search for a pattern or multiple patterns in a text. Useful in spam detection and plagiarism detection where multiple patterns are checked.

**Longest Palindromic Substring:**
Finds the longest substring in a string that reads the same forwards and backwards. Used in bioinformatics and data compression.

Each algorithm file includes:

- C++ implementation
- Sample input and output in `main()`
- Console output for demonstration

## Usage

Compile and run any `.cpp` file to see the algorithm in action.

## Example

```
g++ kmp.cpp -o kmp && ./kmp
```
