#pragma once

#include <vector>
#include <string>

// ---------------------------------------------------------------------------
// QuadraticSorts -- O(n^2) sorting algorithms
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/why_sort_data.svg -- why sorting matters, what it enables
// ? SEE DIAGRAM: images/svgs/quadratic_sorts_overview.svg -- the three quadratic sorts at a glance
// ? SEE DIAGRAM: images/svgs/nested_loops_quadratic.svg -- nested loops, math, and O(n²) growth curve
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
// ? SEE DIAGRAM: images/svgs/bubble_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
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
// ? SEE DIAGRAM: images/svgs/insertion_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
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
// ? SEE DIAGRAM: images/svgs/selection_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
//
// ! DISCUSSION: Find the min in unsorted region, swap to front.
//   - Time: O(n^2) always -- no best-case shortcut
//   - Stable: No -- swap can reorder equals
//   - Fewest writes (n-1 swaps total)
//
void selection_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Utility: print a vector (for demo output)
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label = "");
