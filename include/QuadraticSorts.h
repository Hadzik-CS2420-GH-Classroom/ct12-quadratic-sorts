#pragma once

#include <vector>
#include <string>

// ---------------------------------------------------------------------------
// QuadraticSorts -- O(n^2) sorting algorithms
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md
//   - #1 Why Sort Data?
//   - #2 The Three Quadratic Sorts
//   - #3 Why Nested Loops = O(n²)
//
// ! DISCUSSION: Why "quadratic"?
//   - Nested loops: n × n = n² -- when n doubles, runtime quadruples
//
// Key design decisions:
//   - Standalone functions (not inside a class) -- call bubble_sort(data) directly
//   - Take std::vector<int>& by reference -- sorts the original vector in-place
//   - Ascending order (smallest first)
//   - O(1) extra space -- only a few temp variables, no extra arrays needed
//

// ---------------------------------------------------------------------------
// Bubble Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #4 Bubble Sort -- Complete Walkthrough
//
// ! DISCUSSION: Swap adjacent pairs -- largest bubbles to end each pass.
//   - Time: O(n^2) avg/worst | O(n) best (early exit)
//   - Stable: Yes
//
void bubble_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Insertion Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #5 Insertion Sort -- Complete Walkthrough
//
// ! DISCUSSION: Slide each element left into the sorted region.
//   - Time: O(n^2) avg/worst | O(n) best (already sorted)
//   - Stable: Yes
//   - Used as base case in std::sort for n <= 16
//
void insertion_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Selection Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #6 Selection Sort -- Complete Walkthrough
//
// ! DISCUSSION: Find the min in unsorted region, swap to front.
//   - Time: O(n^2) always -- no best-case shortcut
//   - Stable: No -- swap can reorder equals
//   - Fewest writes (n-1 swaps total)
//
void selection_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Summary: Which quadratic sort wins?
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #7 When to Use Which Sort?
// ? SEE DIAGRAM: images/header_diagrams.md #8 O(n²) Sorts -- Side-by-Side Comparison
//

// ---------------------------------------------------------------------------
// Utility: print a vector (for demo output)
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label = "");
