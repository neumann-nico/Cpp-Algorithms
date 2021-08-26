#include "gtest/gtest.h"
#include "BubbleSort/BubbleSort.h"

TEST(BubbleSort, sort_int_1) {
    std::vector<int> vec = {0, 15, 41, 14, 24, 14};

    BubbleSort<int> bubble_sort(vec);
    EXPECT_FALSE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<int>({0, 14, 14, 15, 24, 41}));
}

TEST(BubbleSort, sort_int_2) {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    BubbleSort<int> bubble_sort(vec);
    EXPECT_TRUE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TEST(BubbleSort, sort_int_3) {
    std::vector<int> vec = {5, 4, 3, 2, 1, 0};

    BubbleSort<int> bubble_sort(vec);
    EXPECT_FALSE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TEST(BubbleSort, sort_double_1) {
    std::vector<double> vec = {5.3, 2.34, 1.45, -2.444, 1.0, 0.};

    BubbleSort<double> bubble_sort(vec);
    EXPECT_FALSE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<double>({-2.444, 0., 1.0, 1.45, 2.34, 5.3}));
}

TEST(BubbleSort, sort_float_1) {
    std::vector<float> vec = {5.3f, 2.34f, 1.45f, -2.444f, 1.0f, 0.f};

    BubbleSort<float> bubble_sort(vec);
    EXPECT_FALSE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<float>({-2.444f, 0.f, 1.0f, 1.45f, 2.34f, 5.3f}));
}

TEST(BubbleSort, sort_char_1) {
    std::vector<char> vec = {'g', 'a', 'e', 'z'};

    BubbleSort<char> bubble_sort(vec);
    EXPECT_FALSE(bubble_sort.isSorted());

    bubble_sort.sort();
    EXPECT_TRUE(bubble_sort.isSorted());
    EXPECT_EQ(bubble_sort.getVector(), std::vector<char>({'a', 'e', 'g', 'z'}));
}