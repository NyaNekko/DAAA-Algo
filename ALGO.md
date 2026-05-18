# 📘 DAA Algorithm Overviews — Assignments 1–16

> High-level step-by-step overviews for all 16 assignments.
> Each algorithm describes *what* happens conceptually, not *how* the code implements it.

| # | Topic | Language |
|---|-------|----------|
| 1 | Min-Max using Threads | Java |
| 2 | Linear Search using Threads | Java |
| 3 | Parallel Merge Sort + Binary Search | Java |
| 4 | Parallel Quick Sort + Binary Search | Java |
| 5 | Prim's MST | C++ |
| 6 | Kruskal's MST | C++ |
| 7 | Dijkstra's Shortest Path | C++ |
| 8 | String Permutations (Backtracking) | C++ |
| 9 | Subset Sum (Backtracking) | C++ |
| 10 | N-Queens Problem | C++ |
| 11 | 0/1 Knapsack (DP) | C++ |
| 12 | Fibonacci (3 Approaches) | C++ |
| 13 | Karatsuba Multiplication | C++ |
| 14 | Longest Common Subsequence | C++ |
| 15 | Graph Coloring (Backtracking) | C++ |
| 16 | Hamiltonian Cycle (Backtracking) | C++ |

---

## Assignment 1 — Min-Max using Multithreading

```
Start
Start the program.
Generate a large array of random integers.
Divide the array into equal chunks for each thread.
Create threads, each assigned to find local min and max of its chunk.
Start all threads and wait for them to finish.
Collect local results from all threads.
Compare all local minimums to find overall minimum.
Compare all local maximums to find overall maximum.
Display the overall minimum and maximum.
Stop the program.
End.
```

---

## Assignment 2 — Linear Search using Multithreading

```
Start
Start the program.
Generate a large array of random strings.
Input the search string from the user.
Select search mode: single occurrence or all occurrences.
Divide the array into equal chunks for each thread.
Create threads, each assigned to search its chunk for the target string.
Start all threads and wait for them to finish.
Collect and display the indices found by each thread.
Display the total search time.
Stop the program.
End.
```

---

## Assignment 3 — Parallel Merge Sort + Binary Search

```
Start
Start the program.
Generate a large array of random integers.
Recursively divide the array into two halves.
If recursion depth is within limit, spawn two threads for each half.
Otherwise, sort both halves sequentially.
Merge the two sorted halves into one sorted segment.
Repeat until the full array is sorted.
Input a target value from the user.
Apply Binary Search on the sorted array.
Compare mid element with target; move left or right accordingly.
Display the index of the target or report not found.
Stop the program.
End.
```

---

## Assignment 4 — Parallel Quick Sort + Binary Search

```
Start
Start the program.
Generate a large array of random integers.
Select a pivot and partition the array around it.
If the partition size is small, sort sequentially to avoid overhead.
Otherwise, spawn two threads — one for each partition.
Start both threads and wait for them to finish.
Repeat until all partitions are sorted.
Input a target value from the user.
Apply Binary Search on the sorted array.
Compare mid element with target; narrow search to left or right half.
Display the index of the target or report not found.
Stop the program.
End.
```

---

## Assignment 5 — Prim's Minimum Spanning Tree

```
Start
Start the program.
Input the number of vertices and the edge list with weights.
Build an adjacency matrix from the edge list.
Initialize all key values to infinity; set source key to 0.
Mark all vertices as not yet in MST.
Repeat until all vertices are included:
    Pick the unvisited vertex with the smallest key value.
    Add it to the MST and update the cost.
    Update key values of its unvisited neighbors if a cheaper edge is found.
Display each MST edge and the total minimum cost.
Stop the program.
End.
```

---

## Assignment 6 — Kruskal's Minimum Spanning Tree

```
Start
Start the program.
Input the number of vertices and the edge list with weights.
Sort all edges by weight in ascending order.
Initialize Union-Find structure for cycle detection.
For each edge in sorted order:
    If the two endpoints belong to different components (no cycle):
        Add the edge to MST and merge the components.
    Otherwise skip the edge.
Stop when MST has (V-1) edges.
Display each MST edge and the total minimum cost.
Stop the program.
End.
```

---

## Assignment 7 — Dijkstra's Shortest Path

```
Start
Start the program.
Input the graph with vertices, edges, and weights.
Input the source vertex.
Set distance to source as 0; set all other distances to infinity.
Add source to the priority queue.
While the priority queue is not empty:
    Extract the vertex with the smallest known distance.
    For each neighbor, check if a shorter path is found through current vertex.
    If yes, update its distance and add it to the priority queue.
After all vertices are processed, backtrack using parent pointers to find paths.
Display the shortest distance and path from source to every other vertex.
Stop the program.
End.
```

---

## Assignment 8 — String Permutations (Backtracking)

```
Start
Start the program.
Input a string from the user.
Fix the first character of the string at the current position.
Recurse to generate all permutations of the remaining characters.
When all positions are fixed, print the current permutation.
Backtrack by swapping characters back to their original positions.
Repeat for every character at every position.
Display all permutations and the total count.
Stop the program.
End.
```

---

## Assignment 9 — Subset Sum (Backtracking)

```
Start
Start the program.
Input array elements and the target sum.
At each element, make two choices: include it or exclude it.
Recurse through all elements following both choices.
When all elements are considered, check if the current subset sums to target.
If yes, print the subset.
Backtrack to explore remaining combinations.
If no valid subset is found, report accordingly.
Stop the program.
End.
```

---

## Assignment 10 — N-Queens Problem (Backtracking)

```
Start
Start the program.
Input N (board size).
Initialize an empty N×N chessboard.
Place a queen row by row, trying each column.
Before placing, check if the position is safe (no conflict in column or diagonals).
If safe, place the queen and move to the next row.
If no column is safe in the current row, backtrack to the previous row.
When all N queens are successfully placed, record the solution.
Repeat to find all valid configurations.
Display all solutions and the total count.
Stop the program.
End.
```

---

## Assignment 11 — 0/1 Knapsack (Dynamic Programming)

```
Start
Start the program.
Input number of items, their weights and values, and the knapsack capacity.
Create a DP table of size (items+1) × (capacity+1) initialized to 0.
For each item and each capacity value:
    If the item fits, take the maximum of including or excluding it.
    Otherwise, carry forward the value without the item.
The bottom-right cell of the table gives the maximum profit.
Backtrack through the table to identify which items were selected.
Display the selected items and the maximum profit.
Stop the program.
End.
```

---

## Assignment 12 — Fibonacci (3 Approaches)

```
Start
Start the program.
Input N (the position in the Fibonacci sequence).

Approach 1 — Pure Recursion:
    Return N if N ≤ 1.
    Otherwise recursively compute Fibonacci(N-1) + Fibonacci(N-2).

Approach 2 — Top-Down (Memoization):
    Return N if N ≤ 1.
    If result already computed, return cached value.
    Otherwise compute, cache, and return the result.

Approach 3 — Bottom-Up (Tabulation):
    Initialize base values for positions 0 and 1.
    Iteratively fill up to position N using previous two values.
    Return the value at position N.

Display results from all three approaches.
Stop the program.
End.
```

---

## Assignment 13 — Karatsuba Multiplication (Divide & Conquer)

```
Start
Start the program.
Input two large numbers X and Y.
If either number is a single digit, multiply directly and return.
Split X into two halves: high part (a) and low part (b).
Split Y into two halves: high part (c) and low part (d).
Recursively compute three products:
    Product 1: a × c
    Product 2: b × d
    Product 3: (a+b) × (c+d) − Product1 − Product2  (gives a×d + b×c)
Combine the three products using positional shifts to get the final result.
Display the product.
Stop the program.
End.
```

---

## Assignment 14 — Longest Common Subsequence (LCS)

```
Start
Start the program.
Input two strings str1 and str2.
Find lengths of both strings.
Create a DP table dp[n+1][m+1] initialized with 0.
Compare characters of both strings using nested loops.
If characters match:
    Store dp[i-1][j-1] + 1 in dp[i][j].
Otherwise:
    Store maximum of dp[i-1][j] and dp[i][j-1].
After filling the table, backtrack from the last cell.
If characters match during backtracking:
    Add character to result and move diagonally.
Otherwise move towards the larger value in the table.
Obtain the Longest Common Subsequence string.
Display the LCS.
Stop the program.
End.
```

---

## Assignment 15 — Graph Coloring (Backtracking)

```
Start
Start the program.
Input the number of vertices, edges, and the number of colors available.
Build the graph's adjacency structure.
Assign colors to vertices one by one, starting from vertex 0.
For each vertex, try all available colors.
Before assigning, check that no adjacent vertex has the same color.
If a valid color is found, assign it and move to the next vertex.
If no color is valid, backtrack and try a different color for the previous vertex.
When all vertices are colored, record the solution.
If coloring is impossible with given colors, report accordingly.
Display the color assigned to each vertex.
Stop the program.
End.
```

---

## Assignment 16 — Hamiltonian Cycle (Backtracking)

```
Start
Start the program.
Input the number of vertices and the edge list.
Build the graph's adjacency structure.
Start the path from vertex 0.
Add vertices to the path one by one.
Before adding, check the vertex is adjacent to the last placed vertex and not already visited.
If all vertices are placed, check if the last vertex connects back to vertex 0.
If yes, record the Hamiltonian Cycle.
If not, backtrack and try the next candidate vertex.
Repeat until all possibilities are explored.
Display all Hamiltonian Cycles found or report none exists.
Stop the program.
End.
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
