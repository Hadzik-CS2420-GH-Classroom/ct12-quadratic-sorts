#include <gtest/gtest.h>
#include "QuadraticSorts.h"
#include <algorithm>
#include <numeric>

// =============================================================================
// Helper: verify a vector is sorted in ascending order
// =============================================================================
static bool is_sorted_ascending(const std::vector<int>& data) {
    for (int i = 1; i < static_cast<int>(data.size()); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

// =============================================================================
// Bubble Sort Tests (10 points)
// =============================================================================

TEST(BubbleSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(BubbleSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[4], 5);
}

TEST(BubbleSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(BubbleSort, SingleElement) {
    std::vector<int> data = {42};
    bubble_sort(data);
    EXPECT_EQ(data.size(), 1u);
    EXPECT_EQ(data[0], 42);
}

TEST(BubbleSort, EmptyVector) {
    std::vector<int> data;
    bubble_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(BubbleSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data.size(), 10u);
}

TEST(BubbleSort, AllSameValue) {
    std::vector<int> data = {7, 7, 7, 7, 7};
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(BubbleSort, LargerDataset) {
    std::vector<int> data(100);
    std::iota(data.begin(), data.end(), 0);       // 0..99
    std::reverse(data.begin(), data.end());        // 99..0
    bubble_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 0);
    EXPECT_EQ(data[99], 99);
}

// =============================================================================
// Insertion Sort Tests (10 points)
// =============================================================================

TEST(InsertionSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(InsertionSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[4], 5);
}

TEST(InsertionSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(InsertionSort, SingleElement) {
    std::vector<int> data = {42};
    insertion_sort(data);
    EXPECT_EQ(data[0], 42);
}

TEST(InsertionSort, EmptyVector) {
    std::vector<int> data;
    insertion_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(InsertionSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(InsertionSort, NearlySorted) {
    std::vector<int> data = {1, 2, 4, 3, 5, 6, 8, 7};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(InsertionSort, NegativeNumbers) {
    std::vector<int> data = {-3, 0, -7, 4, -1, 2};
    insertion_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], -7);
    EXPECT_EQ(data[5], 4);
}

// =============================================================================
// Selection Sort Tests (10 points)
// =============================================================================

TEST(SelectionSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    selection_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(SelectionSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    selection_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[4], 5);
}

TEST(SelectionSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    selection_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(SelectionSort, SingleElement) {
    std::vector<int> data = {42};
    selection_sort(data);
    EXPECT_EQ(data[0], 42);
}

TEST(SelectionSort, EmptyVector) {
    std::vector<int> data;
    selection_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(SelectionSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    selection_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(SelectionSort, TwoElements) {
    std::vector<int> data = {9, 1};
    selection_sort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 9);
}

TEST(SelectionSort, LargerDataset) {
    std::vector<int> data(100);
    std::iota(data.begin(), data.end(), 0);
    std::reverse(data.begin(), data.end());
    selection_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 0);
    EXPECT_EQ(data[99], 99);
}
