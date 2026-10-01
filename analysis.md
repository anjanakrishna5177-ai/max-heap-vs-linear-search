# Performance Analysis

## Input

```text
78, 92, 65, 88, 95, 72, 84, 90
```

## Max Heap

Final heap:

```text
95 92 90 78 88 65 72 84
```

The maximum value is always stored at the root.

Therefore:

```text
Maximum retrieval = O(1)
```

The given implementation builds the heap through repeated insertion. For 8 values, it performs 10 parent-child comparisons.

## Linear Search

Linear Search starts with the first score as the current maximum and compares every remaining score.

For `n` elements:

```text
Number of comparisons = n - 1
```

For 8 scores:

```text
8 - 1 = 7 comparisons
```

Time complexity:

```text
O(n)
```

## Insertion

### Max Heap

A new value is inserted at the end and may move upward.

```text
Average/Worst-case complexity: O(log n)
```

### Linear Search

Appending an item to an array with available space can be:

```text
O(1)
```

But if the maximum must be found again, a linear scan is required:

```text
O(n)
```

## Scaling

| Number of students | Linear Search for maximum | Max Heap retrieval |
|---:|---:|---:|
| n | O(n) | O(1) |
| 100 | Up to 99 comparisons | 0 additional comparisons |
| 1,000 | Up to 999 comparisons | 0 additional comparisons |
| 10,000 | Up to 9,999 comparisons | 0 additional comparisons |

## Conclusion

For a one-time maximum search, Linear Search is simple.

For a system where scores are continuously inserted and the highest score is queried repeatedly, a Max Heap is more suitable because:

- The maximum is always at the root.
- Maximum retrieval is O(1).
- Insertion is O(log n).
- The heap property maintains the maximum automatically.
