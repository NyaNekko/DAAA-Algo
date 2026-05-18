# 📘 DAA Notes — Part 2 (Assignments 9–16)

| # | Topic | Language |
|---|-------|----------|
| 9 | Subset Sum (Backtracking) | C++ |
| 10 | N-Queens Problem | C++ |
| 11 | 0/1 Knapsack (DP) | C++ |
| 12 | Fibonacci (3 Approaches) | C++ |
| 13 | Karatsuba Multiplication | C++ |
| 14 | Longest Common Subsequence | C++ |
| 15 | Graph Coloring (Backtracking) | C++ |
| 16 | Hamiltonian Cycle (Backtracking) | C++ |

---

## Assignment 9 — Subset Sum (Backtracking)

**Concept:** Find all subsets of an array whose elements sum to a given target using include/exclude recursion.

**Time Complexity:** `O(2ⁿ)` — every element has 2 choices: include or exclude

```
ALGORITHM: Subset Sum

START

Step 1: Read n, then read elements into nums[]

Step 2: Read target sum

Step 3: Initialize ans = [], found = false
        Call getAllSubsets(nums, ans, i=0, target, found)

Step 4: Inside getAllSubsets(nums, ans, i, target, found):
        If i == n (all elements considered):
            If sum of ans == target, print ans and set found = true
            Return

Step 5: Include nums[i]:
        Add nums[i] to ans
        Recurse with i+1

Step 6: Backtrack:
        Remove nums[i] from ans

Step 7: Exclude nums[i]:
        Recurse with i+1 (without nums[i])

Step 8: If found == false, print "No subset found"

END
```

---

## Assignment 10 — N-Queens Problem (Backtracking)

**Concept:** Place N queens on an N×N chessboard so no two queens share the same row, column, or diagonal.

**Time Complexity:** `O(N!)`

```
ALGORITHM: N-Queens

START

Step 1: Read N (board size and number of queens)

Step 2: Initialize board[N][N] with all '.' (empty board)

Step 3: Initialize ans = []
        Call nQueens(board, row=0, n=N, ans)

Step 4: Inside nQueens(board, row, n, ans):
        If row == n:
            Add board to ans (all N queens placed — solution found)
            Return

Step 5: For each column col from 0 to n-1:
        If isSafe(board, row, col, n):
            Place 'Q' at board[row][col]
            Recurse to next row
            Remove 'Q' (backtrack)

Step 6: Inside isSafe(board, row, col, n):
        Check same row — if any 'Q' found, return false
        Check same column — if any 'Q' found, return false
        Check upper-left diagonal — if any 'Q' found, return false
        Check upper-right diagonal — if any 'Q' found, return false
        Return true (position is safe)

Step 7: Print total solutions count and all board configurations

END
```

---

## Assignment 11 — 0/1 Knapsack (Dynamic Programming)

**Concept:** Maximize total value of selected items without exceeding the weight capacity. Each item can be taken at most once.

**Time Complexity:** `O(n × W)` | **Space:** `O(n × W)`

```
ALGORITHM: 0/1 Knapsack (Bottom-Up DP)

START

Step 1: Read n (number of items)
        Read weights[] and values[] for each item
        Read W (knapsack capacity)

Step 2: Create dp[n+1][W+1], initialize all cells to 0
        dp[i][w] = max value using first i items with capacity w

Step 3: Fill the DP table:
        For each item i from 1 to n:
            For each capacity w from 0 to W:
                If weights[i-1] <= w:
                    dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w])
                Else:
                    dp[i][w] = dp[i-1][w]  (item too heavy, skip)

Step 4: maxProfit = dp[n][W]  (answer is in bottom-right cell)

Step 5: Backtrack to find selected items:
        Start at w = W, traverse i from n down to 1
        If dp[i][w] != dp[i-1][w], item i was included — print it and reduce w

Step 6: Print maxProfit

END
```

---

## Assignment 12 — Fibonacci (3 Approaches)

**Concept:** Compute the Nth Fibonacci number using three strategies of increasing efficiency.

| Approach | Time | Space |
|----------|------|-------|
| Recursive | O(2ⁿ) | O(n) stack |
| Top-Down (Memoization) | O(n) | O(n) |
| Bottom-Up (Tabulation) | O(n) | O(n) |

```
ALGORITHM: Fibonacci (3 Approaches)

START

Step 1: Read n (0 ≤ n ≤ 40)

─────────────────────────────────────────
// APPROACH 1: Pure Recursion — O(2^n)
─────────────────────────────────────────
Step 2: fibRecursive(n):
        If n <= 1, return n
        Return fibRecursive(n-1) + fibRecursive(n-2)

─────────────────────────────────────────
// APPROACH 2: Top-Down Memoization — O(n)
─────────────────────────────────────────
Step 3: fibTopDown(n, dp[]):
        If n <= 1, return n
        If dp[n] != -1, return dp[n]  (cached)
        Store and return dp[n] = fibTopDown(n-1) + fibTopDown(n-2)

─────────────────────────────────────────
// APPROACH 3: Bottom-Up Tabulation — O(n)
─────────────────────────────────────────
Step 4: fibBottomUp(n):
        Set dp[0] = 0, dp[1] = 1
        For i from 2 to n: dp[i] = dp[i-1] + dp[i-2]
        Return dp[n]

Step 5: Print results from all three approaches

END
```

---

## Assignment 13 — Karatsuba Multiplication (Divide & Conquer)

**Concept:** Multiply two large numbers using only 3 recursive multiplications instead of 4, reducing complexity.

**Formula:** `x × y = ac × 10^(2m) + (ad+bc) × 10^m + bd`
Key trick: `ad + bc = (a+b)(c+d) − ac − bd`

**Time Complexity:** `O(n^1.585)` vs `O(n²)` for standard multiplication

```
ALGORITHM: Karatsuba Multiplication

START

Step 1: Read two numbers x and y

Step 2: Call karatsuba(x, y) and print result

Step 3: Inside karatsuba(x, y):
        If x < 10 or y < 10, return x * y  (base case: single digit)

Step 4: Calculate n = max digits of x and y
        Set m = n / 2, p = 10^m

Step 5: Split x into upper half a = x / p and lower half b = x % p
        Split y into upper half c = y / p and lower half d = y % p

Step 6: Compute 3 recursive multiplications:
        ac   = karatsuba(a, c)
        bd   = karatsuba(b, d)
        ad_bc = karatsuba(a+b, c+d) - ac - bd

Step 7: Return ac * 10^(2m) + ad_bc * 10^m + bd

END
```

---

## Assignment 14 — Longest Common Subsequence (LCS)

**Concept:** Find the longest sequence of characters that appears in both strings in the same relative order (not necessarily contiguous).

**Time Complexity:** `O(n × m)` | **Space:** `O(n × m)`

```
ALGORITHM: Longest Common Subsequence

START

Step 1: Read str1 (length n) and str2 (length m)

Step 2: Create dp[n+1][m+1], initialize all cells to 0
        dp[i][j] = LCS length of str1[0..i-1] and str2[0..j-1]

Step 3: Fill the DP table:
        For each i from 1 to n, for each j from 1 to m:
            If str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1  (characters match)
            Else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Step 4: LCS length = dp[n][m]

Step 5: Backtrack to recover LCS string:
        Start at i = n, j = m
        If str1[i-1] == str2[j-1], add to result and move diagonally
        Else move toward larger of dp[i-1][j] and dp[i][j-1]

Step 6: Print LCS string and its length

END
```

---

## Assignment 15 — Graph Coloring (Backtracking)

**Concept:** Assign colors (1 to m) to vertices so that no two adjacent vertices share the same color.

**Time Complexity:** `O(mᵛ)` worst case

```
ALGORITHM: Graph Coloring

START

Step 1: Read vertices V and edges E
        Build adjacency matrix adj[V][V]

Step 2: Read m (number of colors available)

Step 3: Initialize color[v] = 0 for all v  (0 = uncolored)

Step 4: Call graphColor(vertex=0, m)

Step 5: Inside graphColor(v, m):
        If v == V, return true  (all vertices successfully colored)

Step 6: For each color c from 1 to m:
        If isSafe(v, c) (no adjacent vertex has color c):
            Assign color[v] = c
            If graphColor(v+1, m) returns true, propagate success
            Else, unassign color[v] = 0  (backtrack)

Step 7: Return false if no valid color found for this vertex

Step 8: Inside isSafe(v, c):
        For each vertex u adjacent to v:
            If color[u] == c, return false
        Return true

Step 9: If solution exists, print "Vertex v → Color color[v]" for each vertex
        Else print "No solution with m colors"

END
```

---

## Assignment 16 — Hamiltonian Cycle (Backtracking)

**Concept:** Find all cycles that visit every vertex exactly once and return to the starting vertex.

**Time Complexity:** `O(V!)`

```
ALGORITHM: Hamiltonian Cycle

START

Step 1: Read vertices V and edges E
        Build adjacency matrix adj[V][V]

Step 2: Initialize path[V] = {-1, -1, ..., -1}  (all positions unset)

Step 3: Set path[0] = 0  (always start from vertex 0)

Step 4: Initialize allCycles = []

Step 5: Call solve(path, pos=1, allCycles)

Step 6: Inside solve(path, pos, allCycles):
        If pos == V (all vertices placed):
            If there is an edge from path[V-1] back to path[0]:
                Add current path to allCycles  (valid Hamiltonian cycle)
            Return

Step 7: For each vertex v from 1 to V-1:
        If isSafe(v, path, pos):
            Add v to path[pos]
            Recurse to next position
            Remove v from path[pos]  (backtrack)

Step 8: Inside isSafe(v, path, pos):
        If no edge from path[pos-1] to v, return false
        If v is already in path[], return false
        Return true

Step 9: If allCycles is empty, print "No Hamiltonian Cycle exists"
        Else for each cycle, print: v0 → v1 → ... → vn → v0
        Print total number of cycles found

END
```

---

## 📊 Algorithm Summary Table

| # | Algorithm | Paradigm | Time Complexity | Space |
|---|-----------|----------|-----------------|-------|
| 1 | Min-Max Threads | Divide & Conquer | O(n/k) per thread | O(k) |
| 2 | Linear Search Threads | Brute Force | O(n/k) per thread | O(k) |
| 3 | Merge Sort + Binary Search | Divide & Conquer | O(n log n) / O(log n) | O(n) |
| 4 | Quick Sort + Binary Search | Divide & Conquer | O(n log n) / O(log n) | O(log n) |
| 5 | Prim's MST | Greedy | O(V²) | O(V) |
| 6 | Kruskal's MST | Greedy | O(E log E) | O(V) |
| 7 | Dijkstra's SSSP | Greedy | O((V+E) log V) | O(V) |
| 8 | String Permutations | Backtracking | O(n!) | O(n) |
| 9 | Subset Sum | Backtracking | O(2ⁿ) | O(n) |
| 10 | N-Queens | Backtracking | O(N!) | O(N²) |
| 11 | 0/1 Knapsack | Dynamic Programming | O(n × W) | O(n × W) |
| 12 | Fibonacci | Recursion / DP | O(2ⁿ) / O(n) / O(n) | varies |
| 13 | Karatsuba Multiply | Divide & Conquer | O(n^1.585) | O(log n) |
| 14 | LCS | Dynamic Programming | O(n × m) | O(n × m) |
| 15 | Graph Coloring | Backtracking | O(mᵛ) | O(V) |
| 16 | Hamiltonian Cycle | Backtracking | O(V!) | O(V) |

---

## 📝 Paradigm Cheat Sheet

### Divide & Conquer
> Split problem → Solve each half → Combine results
> Examples: Merge Sort, Quick Sort, Karatsuba, Binary Search

### Greedy
> Always pick the locally optimal choice at each step
> Examples: Prim's MST, Kruskal's MST, Dijkstra's

### Backtracking
> Try every option → If invalid, undo (backtrack) → Try next
> Examples: N-Queens, Graph Coloring, Hamiltonian Cycle, Subset Sum, Permutations

### Dynamic Programming
> Break into overlapping subproblems → Cache results → Build final answer
> Examples: Fibonacci, 0/1 Knapsack, LCS
