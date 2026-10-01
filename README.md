# Max Heap vs Linear Search – Highest Student Score

## 📌 Problem Statement

A university wants to identify the highest student score from the following data:

```text
78, 92, 65, 88, 95, 72, 84, 90
```

This project:

1. Implements a **Max Heap** and inserts all the scores.
2. Records the heap arrangement after every insertion.
3. Finds the highest score using:
   - Max Heap
   - Linear Search
4. Counts the comparisons/operations required.
5. Compares the performance of both approaches.
6. Determines which data structure is suitable for continuously maintaining the highest score.

---

## 📂 Project Structure

```text
max-heap-vs-linear-search/
│
├── README.md
├── max_heap.c
├── linear_search.c
├── comparison.c
├── output.txt
└── analysis.md
```

---

## 🧮 Input

```text
78 92 65 88 95 72 84 90
```

Number of students:

```text
8
```

---

# 1. Max Heap

A Max Heap is a complete binary tree in which every parent is greater than or equal to its children.

The maximum element is always stored at the root.

### Heap after every insertion

| Step | Inserted Score | Heap |
|---:|---:|---|
| 1 | 78 | `78` |
| 2 | 92 | `92 78` |
| 3 | 65 | `92 78 65` |
| 4 | 88 | `92 88 65 78` |
| 5 | 95 | `95 92 65 78 88` |
| 6 | 72 | `95 92 72 78 88 65` |
| 7 | 84 | `95 92 84 78 88 65 72` |
| 8 | 90 | `95 92 90 78 88 65 72 84` |

### Final Max Heap

```text
          95
        /    \
      92      90
     /  \    /  \
   78   88  65   72
  /
 84
```

The maximum score is therefore:

```text
95
```

---

# 2. Linear Search

Linear Search checks the scores one by one while keeping track of the largest value found so far.

```text
78 → 92 → 65 → 88 → 95 → 72 → 84 → 90
```

Comparisons:

```text
78 vs 92
92 vs 65
92 vs 88
92 vs 95
95 vs 72
95 vs 84
95 vs 90
```

Total comparisons:

```text
7
```

Maximum:

```text
95
```

---

# 3. Comparison

| Operation | Max Heap | Linear Search |
|---|---:|---:|
| Find maximum | O(1) | O(n) |
| Maximum retrieval for this data | 0 additional comparisons | 7 comparisons |
| Insert a new score | O(log n) | O(1) if appended |
| Maintain maximum after insertion | Yes | Requires another search |
| Suitable for repeated maximum queries | Yes | Less suitable |

### Construction

Building the Max Heap using repeated insertion takes:

```text
O(n log n)
```

for `n` scores.

For the given insertion process, the program performs **10 parent comparisons**.

---

# 4. Performance Analysis

### Finding the maximum

For a Max Heap, the maximum is always at the root.

```text
max = heap[0]
```

Therefore:

```text
Time Complexity = O(1)
```

Linear Search may need to examine every score:

```text
Time Complexity = O(n)
```

For 8 scores, Linear Search requires:

```text
8 - 1 = 7 comparisons
```

---

### Inserting a new score

In a Max Heap, the new element is inserted at the end and moved upward until the heap property is restored.

```text
Time Complexity = O(log n)
```

With Linear Search, adding a score to an array can be O(1) if there is free space, but finding the new maximum afterward requires:

```text
O(n)
```

---

### Increasing the number of students

As the number of students increases, Linear Search requires more comparisons when finding the maximum.

For a Max Heap, retrieving the maximum remains:

```text
O(1)
```

Only insertion requires:

```text
O(log n)
```

This makes a Max Heap useful when scores are continuously added and the highest score needs to be queried frequently.

---

# 5. Conclusion

For a single search through a small list, Linear Search is simple and easy to implement.

However, when a university continuously receives new student scores and frequently needs to know the highest score, a **Max Heap is more suitable**.

The reason is:

- Maximum is always available at the root.
- Maximum retrieval takes O(1).
- New scores can be inserted in O(log n).
- The heap automatically maintains the highest score.

Therefore, for continuously maintaining and retrieving the highest score, the **Max Heap approach is appropriate**.

---

## ▶️ How to Compile and Run

### GCC

Compile the Max Heap program:

```bash
gcc max_heap.c -o max_heap
```

Run:

```bash
./max_heap
```

Compile Linear Search:

```bash
gcc linear_search.c -o linear_search
```

Run:

```bash
./linear_search
```

Compile the comparison program:

```bash
gcc comparison.c -o comparison
```

Run:

```bash
./comparison
```

### Windows

If using MinGW GCC:

```bash
gcc max_heap.c -o max_heap.exe
max_heap.exe
```

---

## 🛠️ Technologies Used

- C
- Data Structures
- Max Heap
- Linear Search
- Time Complexity Analysis

---

## 👩‍💻 Author

**Anjana Krishna K**

Computer Science Engineering  
Vimal Jyothi Engineering College
