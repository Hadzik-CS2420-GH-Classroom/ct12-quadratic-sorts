# CT12 -- O(n^2) Sorting Algorithms

## Overview

An in-class code-together activity introducing **quadratic sorting algorithms** -- bubble sort, insertion sort, and selection sort. Students implement all three algorithms in `QuadraticSorts.cpp` and call them from `main.cpp` to sort exam scores. The activity covers nested-loop patterns, best/worst case analysis, stability, and why insertion sort is the practical winner among O(n^2) sorts.

## Learning Objectives

- Implement **bubble sort** with the early-exit optimization (no swaps = already sorted)
- Implement **insertion sort** using the shift-right pattern to insert each element into the sorted region
- Implement **selection sort** by finding the minimum and swapping to the front
- Explain why all three are **O(n^2)** average case (nested loops over n elements)
- Explain why insertion sort and bubble sort have **O(n) best case** but selection sort does not
- Explain **stability**: bubble and insertion sort are stable; selection sort is not

## Files

| File | Focus | TODOs |
|---|---|---|
| `QuadraticSorts.cpp` | Implement bubble, insertion, and selection sort | 3 |
| `main.cpp` | Call each sort on exam scores, compare results | 4 |

## Teaching Order

### 1. `QuadraticSorts.h` -- Function declarations

Walk through the header. Discuss why these are free functions (not class methods) and the Big-O annotations.

### 2. `QuadraticSorts.cpp` -- Sort implementations (3 TODOs)

1. **TODO 1: Bubble sort** -- nested loops, adjacent swaps, early exit
2. **TODO 2: Insertion sort** -- save key, shift right, place key
3. **TODO 3: Selection sort** -- find minimum, swap to front

### 3. `main.cpp` -- Exam Score Sorter (4 TODOs)

1. **TODO 1: Bubble sort demo** -- sort and print exam scores
2. **TODO 2: Insertion sort demo** -- same scores, different algorithm
3. **TODO 3: Selection sort demo** -- same scores, different algorithm
4. **TODO 4: Already-sorted input** -- show best-case differences

## Grading (30 points)

| Category | Points | What is tested |
|---|---|---|
| Build | 2 | Project compiles without errors |
| Bubble sort | 10 | Basic, already sorted, reverse, empty, duplicates, large dataset |
| Insertion sort | 10 | Basic, already sorted, reverse, empty, duplicates, nearly sorted, negatives |
| Selection sort | 8 | Basic, already sorted, reverse, empty, duplicates, two elements, large dataset |

## Key Concepts

- **Nested loops = O(n^2)**: outer loop runs n times, inner loop runs ~n times
- **Early exit**: bubble sort and insertion sort can finish early on sorted/nearly-sorted input
- **Stability**: equal elements keep their original order (bubble, insertion) or don't (selection)
- **In-place**: all three use O(1) extra space -- no temporary arrays needed
- **Practical choice**: insertion sort wins among O(n^2) sorts -- fast on small/nearly-sorted data
