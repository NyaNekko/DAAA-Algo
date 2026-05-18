
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

---

## Assignment 1 — Min-Max using Multithreading

**Concept:** Split 1,000,000 random integers into 5 chunks. Each thread finds its own min & max. Main thread combines all results.

**Time Complexity:** `O(n/k)` per thread | **Threads:** 5

```
ALGORITHM: Min-Max using Threads

START

Step 1: Generate ARR[] with 1,000,000 random integers

Step 2: Record startTime for performance measurement

Step 3: Create threads[] of size THREAD_COUNT

Step 4: Calculate start and end indices for each thread's assigned portion
        Create minmaxThread for ARR[start..end]
        Start thread execution

Step 5: Wait for all threads to complete execution

Step 6: Initialize overallMin = MAX_INT
        Initialize overallMax = MIN_INT

Step 7: Traverse ARR[]
        Update overallMin and overallMax accordingly

Step 8: Print overallMin and overallMax

Step 9: Record endTime
        Print elapsed execution time in milliseconds

END
```

---

## Assignment 2 — Linear Search using Multithreading

**Concept:** Search for a string across 1,000,000 random strings using 5 threads. Supports single or multiple occurrence mode.

**Time Complexity:** `O(n/k)` per thread

```
ALGORITHM: Linear Search using Threads

START

Step 1: Generate names[] with 1,000,000 random 5-char strings

Step 2: Read searchName from user

Step 3: Read mode from user ('s' = single match, 'm' = multiple matches)

Step 4: Record startTime

Step 5: Calculate start and end indices for each thread's assigned portion
        Create SearchTask for names[start..end] with searchName and mode
        Start thread execution

Step 6: Inside each thread — traverse assigned portion
        If names[j] matches searchName, print thread name and index found
        If mode is single, stop this thread after first match

Step 7: Wait for all threads to complete execution

Step 8: Record endTime
        Print elapsed execution time in milliseconds

END
```

---

## Assignment 3 — Parallel Merge Sort + Binary Search

**Concept:** Use threads at each recursion level (up to depth 3) to sort in parallel, then Binary Search the sorted array.

**Time Complexity:** Merge Sort `O(n log n)` | Binary Search `O(log n)`

```
ALGORITHM: Parallel Merge Sort + Binary Search

START

Step 1: Generate arr[] with 1,000,000 random integers

Step 2: Create MergeSortThread for arr[0..n-1] at depth 0
        Start and join the thread to begin sorting

Step 3: Inside mergeSort(left, right, depth):
        If left >= right, return (base case: single element)

Step 4: Calculate mid = left + (right - left) / 2

Step 5: If depth < MAX_DEPTH (3):
            Spawn two threads — one for left half, one for right half
            Start both threads and wait for both to finish
        Else:
            Recursively sort both halves sequentially

Step 6: Merge the two sorted halves into one sorted segment

Step 7: Inside merge(left, mid, right):
        Use a temporary array to merge arr[left..mid] and arr[mid+1..right]
        Copy merged result back to arr[left..right]

Step 8: Read target from user
        Apply Binary Search on sorted arr[]
        If arr[mid] == target, return index
        Narrow search to left or right half accordingly

Step 9: Print index of target or "not found"

END
```

---

## Assignment 4 — Parallel Quick Sort + Binary Search

**Concept:** Spawn threads for each partition. For small segments (< 10,000 elements), use sequential sort to avoid thread creation overhead.

**Time Complexity:** Quick Sort avg `O(n log n)` | Binary Search `O(log n)`

```
ALGORITHM: Parallel Quick Sort + Binary Search

START

Step 1: Generate arr[] with 1,000,000 random integers

Step 2: Record startTime

Step 3: Call quickSort(arr, low=0, high=n-1)

Step 4: Inside quickSort(arr, low, high):
        If low >= high, return (base case)

Step 5: If segment size < 10,000:
            Apply sequential quickSort to avoid thread overhead
            Return

Step 6: Partition arr[low..high] around a pivot
        Place pivot in its correct sorted position
        Return pivotIndex

Step 7: Spawn two threads — one for left partition, one for right partition
        Start both threads and wait for both to finish

Step 8: Inside partition(arr, low, high):
        Choose arr[high] as pivot
        Rearrange elements: smaller to left, larger to right
        Return final pivot index

Step 9: Record endTime
        Print elapsed time

Step 10: Read target from user
         Apply Binary Search on sorted arr[]
         Return index if found, else return -1

Step 11: Print result

END
```

---

## Assignment 5 — Prim's MST (Minimum Spanning Tree)

**Concept:** Greedily add the lowest-weight edge connecting the MST to a new unvisited vertex. Uses adjacency matrix.

**Time Complexity:** `O(V²)`

```
ALGORITHM: Prim's Minimum Spanning Tree

START

Step 1: Read number of vertices V
        Read edges with weights, build adjMatrix[V][V]

Step 2: Initialize:
        key[0] = 0, key[v] = INF for all v > 0
        inMST[v] = false for all v
        parent[v] = -1 for all v
        totalCost = 0

Step 3: Repeat V times:

        Step 3a: Find vertex u with minimum key[] where inMST[u] == false
                 If no such vertex, break (graph is disconnected)

        Step 3b: Mark inMST[u] = true
                 If parent[u] != -1, print edge (parent[u]—u) and add key[u] to totalCost

        Step 3c: For each unvisited neighbor v of u:
                 If adjMatrix[u][v] < key[v]:
                     Update key[v] = adjMatrix[u][v]
                     Set parent[v] = u

Step 4: Print totalCost

END
```

---

## Assignment 6 — Kruskal's MST (Minimum Spanning Tree)

**Concept:** Sort edges by weight, add each edge if it doesn't create a cycle. Cycle detection uses Union-Find.

**Time Complexity:** `O(E log E)`

```
ALGORITHM: Kruskal's Minimum Spanning Tree

START

Step 1: Read vertices V and edges[] with weights

Step 2: Sort edges[] by weight in ascending order

Step 3: Initialize Union-Find:
        parent[i] = i for all i
        rank[i] = 0 for all i

Step 4: Initialize mstEdges = [], totalCost = 0

Step 5: For each edge (u, v, w) in sorted order:
        If find(u) != find(v) (no cycle):
            Add (u, v, w) to mstEdges
            Union(u, v)
            Add w to totalCost
            Print edge added
            If mstEdges has V-1 edges, stop (MST complete)
        Else:
            Print edge skipped (would create cycle)

Step 6: Print totalCost and all MST edges

Step 7: find(x) with path compression:
        If parent[x] != x, recursively find root and compress path
        Return parent[x]

Step 8: union(x, y) by rank:
        Find roots px and py
        Attach lower-rank root under higher-rank root
        Increment rank if both are equal

END
```

---

## Assignment 7 — Dijkstra's Shortest Path

**Concept:** Find shortest path from a source to all vertices in a weighted graph (no negative edges). Uses a min-priority set.

**Time Complexity:** `O((V + E) log V)`

```
ALGORITHM: Dijkstra's Shortest Path

START

Step 1: Read graph G(V, E) with edge weights (all >= 0)

Step 2: Read source vertex src

Step 3: Initialize:
        dist[src] = 0
        dist[v] = INF for all v != src
        parent[v] = -1 for all v

Step 4: Insert (dist=0, src) into min-priority set

Step 5: While set is not empty:
        Extract (d, u) with minimum distance
        If d > dist[u], skip (stale entry)

        For each neighbor (v, weight) of u:
            If dist[u] + weight < dist[v]:
                Update dist[v] = dist[u] + weight
                Set parent[v] = u
                Insert (dist[v], v) into set

Step 6: For each vertex v:
        If dist[v] == INF, print "No path"
        Else print dist[v] and backtrack parent[] to show full path

END
```

---

## Assignment 8 — String Permutations (Backtracking)

**Concept:** Generate all permutations of a string by fixing one character at each position and recursing on the rest.

**Time Complexity:** `O(n!)` — 8! = 40,320 permutations max

```
ALGORITHM: String Permutations

START

Step 1: Read string str from user
        Validate: only alphabets, length 1–8

Step 2: Initialize count = 0
        Call permutation(str, start=0, end=len-1, count)

Step 3: Inside permutation(str, start, end, count):
        If start == end:
            Print str (one complete permutation)
            Increment count
            Return

Step 4: For each position i from start to end:
        Swap str[start] and str[i]         (fix character at position 'start')
        Recurse: permutation(str, start+1, end, count)
        Swap back str[start] and str[i]    (backtrack)

Step 5: Print "Total permutations: " + count

END
```

---
*Continue → DAA_Notes_Part2.md (Assignments 9–16)*
