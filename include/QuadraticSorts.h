#pragma once

#include <vector>
#include <string>

// ---------------------------------------------------------------------------
// QuadraticSorts -- O(n^2) sorting algorithms
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/why_sort_data.svg -- why sorting matters, what it enables
// ? SEE DIAGRAM: images/svgs/quadratic_sorts_overview.svg -- the three quadratic sorts at a glance
//
// ! DISCUSSION: Why "quadratic"?
//   - Nested loops: n × n = n² -- when n doubles, runtime quadruples
//
// Key design decisions:
//   - Free functions taking std::vector<int>& (not class methods)
//   - Ascending order, in-place O(1) space
//

// ---------------------------------------------------------------------------
// Bubble Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/bubble_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
//
// ! DISCUSSION: How bubble sort works.
//   - compare each pair of adjacent elements
//   - if they're out of order, swap them
//   - after one full pass, the LARGEST element has "bubbled" to the end
//   - repeat for the remaining unsorted portion
//   - early exit: if a full pass makes NO swaps, the array is already sorted
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(n^2) average/worst | O(n) best (already sorted, with early exit)
//   - Space: O(1) -- in-place
//   - Stable: Yes -- only swaps adjacent elements, so equal values never pass each other
//   - Simple to understand but slow -- mainly used as a teaching tool
//
void bubble_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Insertion Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/insertion_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
//
// ! DISCUSSION: How insertion sort works.
//   - divide the array into a "sorted region" (left) and "unsorted region" (right)
//   - start with the first element as the sorted region (a single element is sorted)
//   - take the next unsorted element (the "key") and slide it left into the correct
//     position by shifting larger elements right
//   - repeat until the entire array is sorted
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(n^2) average/worst | O(n) best (already sorted -- no shifts needed)
//   - Space: O(1) -- in-place
//   - Stable: Yes -- uses > (not >=), so equal elements are never swapped past each other
//   - Fast on small or nearly-sorted data
//   - Used as the base case inside std::sort for n <= 16
//
void insertion_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Selection Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/svgs/selection_sort_complete.svg -- full walkthrough on [5,2,8,1,4]
//
// ! DISCUSSION: How selection sort works.
//   - find the MINIMUM element in the unsorted region
//   - swap it with the first element of the unsorted region
//   - the sorted region grows by one from the left
//   - repeat until the entire array is sorted
//
// ! DISCUSSION: Complexity and properties.
//   - Time: O(n^2) ALWAYS -- no best-case shortcut, always scans the full unsorted region
//   - Space: O(1) -- in-place
//   - Stable: No -- swapping a distant element can jump over equal elements
//     example: [3a, 3b, 1] -> find min (1), swap with 3a -> [1, 3b, 3a] -- order broken
//   - Only n-1 swaps total (fewest writes of any quadratic sort)
//   - Useful when writes are expensive (e.g., flash memory)
//
void selection_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Utility: print a vector (for demo output)
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label = "");
