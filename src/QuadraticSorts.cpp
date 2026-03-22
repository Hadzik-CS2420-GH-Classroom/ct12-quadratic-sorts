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
// ? SEE DIAGRAM: images/cpp_diagrams.md #1 Bubble Sort -- Code + Array State
// ? SEE DIAGRAM: images/cpp_diagrams.md #2 Bubble Sort -- One Pass
// ? SEE DIAGRAM: images/cpp_diagrams.md #3 Bubble Sort -- Early Exit Optimization
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

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ---------------------------------------------------------------------------
// 2. Insertion Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #4 Insertion Sort -- Code + Array State
// ? SEE DIAGRAM: images/cpp_diagrams.md #5 Insertion Sort -- Inserting One Element
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

    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

// ---------------------------------------------------------------------------
// 3. Selection Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #6 Selection Sort -- Code + Array State
// ? SEE DIAGRAM: images/cpp_diagrams.md #7 Selection Sort -- Find Minimum, Swap to Front
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

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
        }
    }
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
