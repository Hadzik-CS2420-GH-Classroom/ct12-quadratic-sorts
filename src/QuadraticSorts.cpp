// =============================================================================
// CT12: O(n^2) Sorting Algorithms
// =============================================================================
//
// Three quadratic sorts that use nested loops to sort an array.
// All three are in-place (O(1) extra space) and work on std::vector<int>.
//
// Scenario: sorting student exam scores in ascending order.
//

#include "QuadraticSorts.h"
#include <iostream>
#include <algorithm>  // std::swap

// ---------------------------------------------------------------------------
// 1. Bubble Sort
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How bubble sort works.
//   - compare each pair of adjacent elements
//   - if they're out of order, swap them
//   - after one full pass, the LARGEST element has "bubbled" to the end
//   - repeat for the remaining unsorted portion
//   - early exit: if a full pass makes NO swaps, the array is already sorted
//
// ! DISCUSSION: Why bubble sort is O(n^2).
//   - outer loop: n passes
//   - inner loop: up to n comparisons per pass
//   - total comparisons: n + (n-1) + (n-2) + ... + 1 = n(n-1)/2 = O(n^2)
//   - best case O(n): already sorted, the first pass finds no swaps and exits
//
void bubble_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());

    // TODO 1: Implement bubble sort
    //   - outer loop: i from 0 to n-1 (each pass places one more element)
    //   - track a bool "swapped" -- set to false at the start of each pass
    //   - inner loop: j from 0 to n-2-i (shrinks each pass -- last i elements are sorted)
    //     - if data[j] > data[j+1], swap them and set swapped = true
    //   - after the inner loop: if !swapped, break (array is sorted -- early exit)
}

// ---------------------------------------------------------------------------
// 2. Insertion Sort
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How insertion sort works.
//   - divide the array into a "sorted region" (left) and "unsorted region" (right)
//   - start with the first element as the sorted region (a single element is sorted)
//   - take the next unsorted element (the "key") and insert it into the correct
//     position in the sorted region by shifting larger elements right
//   - repeat until the entire array is sorted
//
// ! DISCUSSION: Why insertion sort is O(n^2) average but O(n) best case.
//   - worst case (reverse sorted): each element shifts all the way to position 0
//     total shifts: 1 + 2 + 3 + ... + (n-1) = O(n^2)
//   - best case (already sorted): each element is already in position -- no shifts
//     just one comparison per element = O(n)
//   - this makes insertion sort excellent for nearly-sorted data
//
// ! DISCUSSION: Stability.
//   - insertion sort is STABLE: equal elements keep their original relative order
//   - the while loop uses > (not >=), so equal elements are never swapped past each other
//   - this matters when sorting objects by one field -- other fields stay in order
//
void insertion_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());

    // TODO 2: Implement insertion sort
    //   - outer loop: i from 1 to n-1 (element 0 is already "sorted")
    //   - save data[i] as the "key" -- the element we're inserting
    //   - set j = i - 1 (start of the sorted region, scanning right to left)
    //   - while j >= 0 AND data[j] > key:
    //       shift data[j] one position right: data[j+1] = data[j]
    //       decrement j
    //   - place the key at data[j+1] (the correct sorted position)
}

// ---------------------------------------------------------------------------
// 3. Selection Sort
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How selection sort works.
//   - find the MINIMUM element in the unsorted region
//   - swap it with the first element of the unsorted region
//   - the sorted region grows by one from the left
//   - repeat until the entire array is sorted
//
// ! DISCUSSION: Why selection sort is ALWAYS O(n^2).
//   - no early exit -- even if the array is already sorted
//   - finding the minimum always requires scanning the entire unsorted region
//   - comparisons: (n-1) + (n-2) + ... + 1 = n(n-1)/2 = O(n^2) always
//   - BUT: only n-1 swaps total (fewer writes than bubble sort)
//
// ! DISCUSSION: Stability.
//   - selection sort is NOT stable
//   - swapping a distant element into position can jump over equal elements
//   - example: [3a, 3b, 1] -> find min (1), swap with 3a -> [1, 3b, 3a]
//     3a and 3b swapped their relative order
//
void selection_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());

    // TODO 3: Implement selection sort
    //   - outer loop: i from 0 to n-2
    //   - set min_idx = i (assume current position holds the minimum)
    //   - inner loop: j from i+1 to n-1
    //     - if data[j] < data[min_idx], update min_idx = j
    //   - after inner loop: if min_idx != i, swap data[i] and data[min_idx]
}

// ---------------------------------------------------------------------------
// Utility: print a vector
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) {
        std::cout << label;
    }
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(data.size()); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
}
