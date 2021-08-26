#include "gtest/gtest.h"
#include "QuickSort/QuickSort.h"

TEST(QuickSort, sort_int_1) {
    std::vector<int> vec = {0, 15, 41, 14, 24, 14};

    QuickSort<int> quick_sort(vec);
    EXPECT_FALSE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<int>({0, 14, 14, 15, 24, 41}));
}

TEST(QuickSort, sort_int_2) {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    QuickSort<int> quick_sort(vec);
    EXPECT_TRUE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TEST(QuickSort, sort_int_3) {
    std::vector<int> vec = {5, 4, 3, 2, 1, 0};

    QuickSort<int> quick_sort(vec);
    EXPECT_FALSE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TEST(QuickSort, sort_int_4) {
    std::vector<int> vec = {1};

    QuickSort<int> quick_sort(vec);
    EXPECT_TRUE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<int>({1}));
}

TEST(QuickSort, sort_int_5) {
    std::vector<int> vec;

    QuickSort<int> quick_sort(vec);
    EXPECT_TRUE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<int>());
}


TEST(QuickSort, sort_double_1) {
    std::vector<double> vec = {5.3, 2.34, 1.45, -2.444, 1.0, 0.};

    QuickSort<double> quick_sort(vec);
    EXPECT_FALSE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<double>({-2.444, 0., 1.0, 1.45, 2.34, 5.3}));
}

TEST(QuickSort, sort_float_1) {
    std::vector<float> vec = {5.3f, 2.34f, 1.45f, -2.444f, 1.0f, 0.f};

    QuickSort<float> quick_sort(vec);
    EXPECT_FALSE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<float>({-2.444f, 0.f, 1.0f, 1.45f, 2.34f, 5.3f}));
}

TEST(QuickSort, sort_char_1) {
    std::vector<char> vec = {'g', 'a', 'e', 'z'};

    QuickSort<char> quick_sort(vec);
    EXPECT_FALSE(quick_sort.isSorted());

    quick_sort.sort();
    EXPECT_TRUE(quick_sort.isSorted());
    EXPECT_EQ(quick_sort.getVector(), std::vector<char>({'a', 'e', 'g', 'z'}));
}