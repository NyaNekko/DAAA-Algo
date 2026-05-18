# Design & Analysis of Algorithms (DAA)
### SY B.Tech — Semester 2
---

## Repository Structure

```
DAAA/
├── assignment1.java   → Min-Max using Multithreading
├── assignment2.java   → Linear Search using Multithreading
├── assignment3.java   → Parallel Merge Sort + Binary Search
├── assignment4.java   → Parallel Quick Sort + Binary Search
├── assignment5.cpp    → Prim's Minimum Spanning Tree
├── assignment6.cpp    → Kruskal's Minimum Spanning Tree
├── assignment7.cpp    → Dijkstra's Shortest Path
├── assignment8.cpp    → String Permutations (Backtracking)
├── assignment9.cpp    → Subset Sum (Backtracking)
├── assignment10.cpp   → N-Queens Problem (Backtracking)
├── assignment11.cpp   → 0/1 Knapsack (Dynamic Programming)
├── assignment12.cpp   → Fibonacci — 3 Approaches
├── assignment13.cpp   → Karatsuba Multiplication (Divide & Conquer)
├── assignment14.cpp   → Longest Common Subsequence (DP)
├── assignment15.cpp   → Graph Coloring (Backtracking)
├── assignment16.cpp   → Hamiltonian Cycle (Backtracking)
├── Algo_1-6.md        → Algorithm notes for Assignments 1–6 (with pseudocode)
└── Algo_7-16.md       → Algorithm notes for Assignments 7–16 (with pseudocode)
```

---

## Assignment Overview

| # | Topic | Language | Paradigm | Time Complexity |
|---|-------|----------|----------|-----------------|
| 1 | Min-Max using Multithreading | Java | Divide & Conquer | O(n/k) per thread |
| 2 | Linear Search using Multithreading | Java | Brute Force | O(n/k) per thread |
| 3 | Parallel Merge Sort + Binary Search | Java | Divide & Conquer | O(n log n) / O(log n) |
| 4 | Parallel Quick Sort + Binary Search | Java | Divide & Conquer | O(n log n) / O(log n) |
| 5 | Prim's MST | C++ | Greedy | O(V²) |
| 6 | Kruskal's MST | C++ | Greedy | O(E log E) |
| 7 | Dijkstra's Shortest Path | C++ | Greedy | O((V+E) log V) |
| 8 | String Permutations | C++ | Backtracking | O(n!) |
| 9 | Subset Sum | C++ | Backtracking | O(2ⁿ) |
| 10 | N-Queens Problem | C++ | Backtracking | O(N!) |
| 11 | 0/1 Knapsack | C++ | Dynamic Programming | O(n × W) |
| 12 | Fibonacci (3 Approaches) | C++ | Recursion / DP | O(2ⁿ) / O(n) / O(n) |
| 13 | Karatsuba Multiplication | C++ | Divide & Conquer | O(n^1.585) |
| 14 | Longest Common Subsequence | C++ | Dynamic Programming | O(n × m) |
| 15 | Graph Coloring | C++ | Backtracking | O(mᵛ) |
| 16 | Hamiltonian Cycle | C++ | Backtracking | O(V!) |

---

## How to Run

### Java (Assignments 1–4)
```bash
javac assignment1.java
java assignment1
```

### C++ (Assignments 5–16)
```bash
g++ -o assignment5 assignment5.cpp
./assignment5
```

> **Note:** Java assignments use multithreading (`Thread` / `Runnable`). Ensure JDK 8+ is installed.  
> C++ assignments require a compiler supporting C++11 or later (`g++ -std=c++11`).

---

## Algorithm Notes

Detailed pseudocode, concepts, and complexity analysis for all 16 assignments are documented in:

- [`Algo_1-6.md`](./Algo_1-6.md) — Assignments 1 to 6
- [`Algo_7-16.md`](./Algo_7-16.md) — Assignments 7 to 16

Each entry includes:
- **Concept** — What the algorithm does and why
- **Pseudocode** — High-level START/END algorithm steps
- **Time & Space Complexity**

---

## Paradigms Covered

| Paradigm | Assignments |
|----------|-------------|
| **Multithreading** | 1, 2, 3, 4 |
| **Greedy** | 5, 6, 7 |
| **Backtracking** | 8, 9, 10, 15, 16 |
| **Dynamic Programming** | 11, 12, 14 |
| **Divide & Conquer** | 3, 4, 13 |

---
