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
// ? SEE DIAGRAM: images/cpp_diagrams.md #2 Why j < n-1-i? The Unsorted Region Shrinks
// ? SEE DIAGRAM: images/cpp_diagrams.md #3 Bubble Sort -- One Pass
// ? SEE DIAGRAM: images/cpp_diagrams.md #4 Bubble Sort -- Early Exit Optimization
//
// ! DISCUSSION: Swap adjacent pairs, largest bubbles to end each pass.
//   - early exit: if a full pass makes NO swaps, the array is already sorted
//   - Time: O(n^2) avg/worst | O(n) best (early exit)
//   - See diagrams #2-#4 for n-1-i shrinking range, one-pass walkthrough, early exit
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
// ? SEE DIAGRAM: images/cpp_diagrams.md #5 Insertion Sort -- Code + Array State
// ? SEE DIAGRAM: images/cpp_diagrams.md #6 Insertion Sort -- Inserting One Element
//
// ! DISCUSSION: Save the key, shift larger elements right, place the key.
//   - Stable: uses > (not >=), so equal elements keep their original order
//   - Time: O(n^2) avg/worst | O(n) best (already sorted, no shifts needed)
//   - See diagrams #5-#6 for code walkthrough and step-by-step shift animation
//
// ? Variables:
//   n         = total number of elements
//   i         = index of the next unsorted element (sorted region is 0..i-1)
//   key       = the value we're inserting into the sorted region
//   shift_pos = scans backward through the sorted region looking for key's spot
//
void insertion_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());  // ? size() returns size_t (unsigned) -- cast to int so shift_pos can go negative

    for (int i = 1; i < n; ++i) {
        // Step 1: save the current element and start at end of sorted region
        int key = data[i];
        int shift_pos = i - 1;

        // Step 2: shift elements > key one position right
        while (shift_pos >= 0 && data[shift_pos] > key) {
            data[shift_pos + 1] = data[shift_pos];
            --shift_pos;
        }

        // Step 3: place key in the gap
        data[shift_pos + 1] = key;
    }
}

// ---------------------------------------------------------------------------
// 3. Selection Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #7 Selection Sort -- Code + Array State
// ? SEE DIAGRAM: images/cpp_diagrams.md #8 Selection Sort -- Find Minimum, Swap to Front
// ? SEE DIAGRAM: images/cpp_diagrams.md #9 Why Selection Sort Is NOT Stable
//
// ! DISCUSSION: Find the min in unsorted region, swap to front.
//   - Time: O(n^2) always -- no early exit, must scan full unsorted region every pass
//   - Only n-1 swaps total (fewest writes of any quadratic sort)
//   - NOT stable: swap teleports elements past equals (see diagram #9)
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
