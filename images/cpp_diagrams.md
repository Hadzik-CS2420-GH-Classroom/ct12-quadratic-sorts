# CT12 -- Implementation Diagrams

Code-block diagrams referenced from `QuadraticSorts.cpp`.

---

## 1. Bubble Sort -- One Pass
*`QuadraticSorts.cpp::bubble_sort()` -- adjacent swaps, largest element bubbles to the end*

![Bubble Sort -- One Pass](svgs/bubble_sort_pass.svg)

---

## 2. Bubble Sort -- Early Exit Optimization
*`QuadraticSorts.cpp::bubble_sort()` -- no swaps in a full pass means the array is sorted*

![Bubble Sort -- Early Exit Optimization](svgs/bubble_sort_early_exit.svg)

---

## 3. Insertion Sort -- Inserting One Element
*`QuadraticSorts.cpp::insertion_sort()` -- save key, shift larger elements right, place key*

![Insertion Sort -- Inserting One Element](svgs/insertion_sort_step.svg)

---

## 4. Selection Sort -- Find Minimum, Swap to Front
*`QuadraticSorts.cpp::selection_sort()` -- scan unsorted region for min, swap into position*

![Selection Sort -- Find Minimum, Swap to Front](svgs/selection_sort_step.svg)
