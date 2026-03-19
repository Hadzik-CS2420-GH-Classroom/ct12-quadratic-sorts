// =============================================================================
// CT12: O(n^2) Sorting Algorithms -- Exam Score Sorter
// =============================================================================
//
// Scenario: sort student exam scores using three quadratic sorting algorithms.
// Compare how each algorithm approaches the same problem differently.
//

#include <iostream>
#include <vector>
#include "QuadraticSorts.h"

int main() {
    std::cout << "=== CT12: O(n^2) Sorting Algorithms ===\n";
    std::cout << "=== Scenario: Sorting Exam Scores ===\n\n";

    // -----------------------------------------------------------------------
    // 1. Bubble Sort -- swap adjacent elements until sorted
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Bubble sort is the simplest sorting algorithm.
    //   - compare neighbors, swap if out of order, repeat
    //   - largest elements "bubble" to the end each pass
    //   - early exit optimization: stop if no swaps in a full pass
    //
    std::cout << "--- Part 1: Bubble Sort ---\n";
    std::vector<int> scores1 = {78, 95, 62, 88, 73, 91, 55, 82};

    // TODO 1: Print the unsorted scores, sort with bubble_sort, print the result
    //   print_vector(scores1, "  Unsorted: ");
    //   bubble_sort(scores1);
    //   print_vector(scores1, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 2. Insertion Sort -- insert each element into the sorted region
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Insertion sort builds the sorted array one element at a time.
    //   - like sorting a hand of cards: pick up one card, slide it into position
    //   - excellent on nearly-sorted data (O(n) best case)
    //   - used as a base case in real-world hybrid sorts (std::sort)
    //
    std::cout << "\n--- Part 2: Insertion Sort ---\n";
    std::vector<int> scores2 = {78, 95, 62, 88, 73, 91, 55, 82};

    // TODO 2: Print the unsorted scores, sort with insertion_sort, print the result
    //   print_vector(scores2, "  Unsorted: ");
    //   insertion_sort(scores2);
    //   print_vector(scores2, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 3. Selection Sort -- find the minimum, swap to front
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Selection sort always does the same number of comparisons.
    //   - no early exit -- always scans the full unsorted region
    //   - but only n-1 swaps (fewer writes than bubble sort)
    //   - NOT stable: swapping distant elements can reorder equal values
    //
    std::cout << "\n--- Part 3: Selection Sort ---\n";
    std::vector<int> scores3 = {78, 95, 62, 88, 73, 91, 55, 82};

    // TODO 3: Print the unsorted scores, sort with selection_sort, print the result
    //   print_vector(scores3, "  Unsorted: ");
    //   selection_sort(scores3);
    //   print_vector(scores3, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 4. Compare: already-sorted input (best case for insertion sort)
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Best-case performance reveals the key difference.
    //   - insertion sort: O(n) on already-sorted data (no shifts needed)
    //   - bubble sort: O(n) with early exit (no swaps in first pass)
    //   - selection sort: still O(n^2) -- always scans the full unsorted region
    //   - this is why insertion sort is preferred in practice among O(n^2) sorts
    //
    std::cout << "\n--- Part 4: Already-Sorted Input ---\n";
    std::vector<int> sorted_scores = {55, 62, 73, 78, 82, 88, 91, 95};

    // TODO 4: Sort an already-sorted array with all three algorithms and print results
    //   Show that all three produce the same output, but note that
    //   insertion sort and bubble sort are O(n) here while selection sort is still O(n^2)
    //
    //   std::vector<int> test1 = sorted_scores;
    //   bubble_sort(test1);
    //   print_vector(test1, "  Bubble:    ");
    //
    //   std::vector<int> test2 = sorted_scores;
    //   insertion_sort(test2);
    //   print_vector(test2, "  Insertion: ");
    //
    //   std::vector<int> test3 = sorted_scores;
    //   selection_sort(test3);
    //   print_vector(test3, "  Selection: ");

    // -----------------------------------------------------------------------
    // 5. Summary
    // -----------------------------------------------------------------------
    std::cout << "\n--- Summary ---\n";
    std::cout << "  Algorithm      | Time (avg) | Time (best) | Space | Stable?\n";
    std::cout << "  ---------------|------------|-------------|-------|---------\n";
    std::cout << "  Bubble Sort    | O(n^2)     | O(n)        | O(1)  | Yes\n";
    std::cout << "  Insertion Sort | O(n^2)     | O(n)        | O(1)  | Yes\n";
    std::cout << "  Selection Sort | O(n^2)     | O(n^2)      | O(1)  | No\n";
    std::cout << "\n  All three are O(n^2) average case.\n";
    std::cout << "  Insertion sort is the best choice among them for real-world use.\n";

    std::cout << "\n=== CT12 Complete ===\n";
    return 0;
}
