# CT12 -- Implementation Diagrams

Code-block diagrams referenced from `QuadraticSorts.cpp`.
Each diagram shows the code on the left and the array state on the right (CT11 style).

---

## 1. Bubble Sort -- Code + Array State
*`QuadraticSorts.cpp::bubble_sort()` -- outer loop shrinks unsorted region, inner loop swaps adjacent pairs, early exit if no swaps*

![Bubble Sort -- Code + Array State](svgs/bubble_sort_implementation.svg)

---

## 2. Why j < n-1-i? The Unsorted Region Shrinks
*`QuadraticSorts.cpp::bubble_sort()` -- each pass settles one more element at the end, so the inner loop range shrinks by 1*

![Why j < n-1-i? The Unsorted Region Shrinks](svgs/bubble_sort_shrinking_range.svg)

---

## 3. Bubble Sort -- One Pass
*`QuadraticSorts.cpp::bubble_sort()` -- step-by-step pass showing 95 bubbling to the end*

![Bubble Sort -- One Pass](svgs/bubble_sort_pass.svg)

---

## 4. Bubble Sort -- Early Exit Optimization
*`QuadraticSorts.cpp::bubble_sort()` -- no swaps in a full pass means the array is sorted*

![Bubble Sort -- Early Exit Optimization](svgs/bubble_sort_early_exit.svg)

---

## 5. Insertion Sort -- Code + Array State
*`QuadraticSorts.cpp::insertion_sort()` -- save key, shift larger elements right, place key in sorted position*

![Insertion Sort -- Code + Array State](svgs/insertion_sort_implementation.svg)

---

## 6. Insertion Sort -- Inserting One Element
*`QuadraticSorts.cpp::insertion_sort()` -- detailed step-by-step of shifting 95 and 78 right to place 62*

![Insertion Sort -- Inserting One Element](svgs/insertion_sort_step.svg)

---

## 7. Selection Sort -- Code + Array State
*`QuadraticSorts.cpp::selection_sort()` -- scan for minimum, swap to front, always O(n^2)*

![Selection Sort -- Code + Array State](svgs/selection_sort_implementation.svg)

---

## 8. Selection Sort -- Find Minimum, Swap to Front
*`QuadraticSorts.cpp::selection_sort()` -- detailed step-by-step of scanning and swapping*

![Selection Sort -- Find Minimum, Swap to Front](svgs/selection_sort_step.svg)
