#include "gtest/gtest.h"
#include "BubbleSort/BubbleSort.h"
#include "InsertionSort/InsertionSort.h"
#include "MergeSort/MergeSort.h"
#include "QuickSort/QuickSort.h"


template<typename T>
class SortingTestInt : public testing::Test {
};

template<typename T>
class SortingTestChar : public testing::Test {
};

template<typename T>
class SortingTestFloat : public testing::Test {
};

template<typename T>
class SortingTestDouble : public testing::Test {
};

TYPED_TEST_SUITE_P(SortingTestInt);
TYPED_TEST_SUITE_P(SortingTestChar);
TYPED_TEST_SUITE_P(SortingTestDouble);
TYPED_TEST_SUITE_P(SortingTestFloat);


TYPED_TEST_P(SortingTestInt, sort_int_1) {
    std::vector<int> vec = {0, 15, 41, 14, 24, 14};

    TypeParam sorter(vec);
    EXPECT_FALSE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<int>({0, 14, 14, 15, 24, 41}));
}

TYPED_TEST_P(SortingTestInt, sort_int_2) {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    TypeParam sorter(vec);
    EXPECT_TRUE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TYPED_TEST_P(SortingTestInt, sort_int_3) {
    std::vector<int> vec = {5, 4, 3, 2, 1, 0};

    TypeParam sorter(vec);
    EXPECT_FALSE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<int>({0, 1, 2, 3, 4, 5}));
}

TYPED_TEST_P(SortingTestInt, sort_int_4) {
    std::vector<int> vec = {1};

    TypeParam sorter(vec);
    EXPECT_TRUE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<int>({1}));
}

TYPED_TEST_P(SortingTestInt, sort_int_5) {
    std::vector<int> vec;

    TypeParam sorter(vec);
    EXPECT_TRUE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<int>());
}


TYPED_TEST_P(SortingTestDouble, sort_double_1) {
    std::vector<double> vec = {5.3, 2.34, 1.45, -2.444, 1.0, 0.};

    TypeParam sorter(vec);
    EXPECT_FALSE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<double>({-2.444, 0., 1.0, 1.45, 2.34, 5.3}));
}


TYPED_TEST_P(SortingTestFloat, sort_float_1) {
    std::vector<float> vec = {5.3f, 2.34f, 1.45f, -2.444f, 1.0f, 0.f};

    TypeParam sorter(vec);
    EXPECT_FALSE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<float>({-2.444f, 0.f, 1.0f, 1.45f, 2.34f, 5.3f}));
}

TYPED_TEST_P(SortingTestChar, sort_char_1) {
    std::vector<char> vec = {'g', 'a', 'e', 'z'};

    TypeParam sorter(vec);
    EXPECT_FALSE(sorter.isSorted());

    sorter.sort();
    EXPECT_TRUE(sorter.isSorted());
    EXPECT_EQ(sorter.getVector(), std::vector<char>({'a', 'e', 'g', 'z'}));
}

using testing::Types;

typedef Types<BubbleSort<char>, InsertionSort<char>, MergeSort<char>, QuickSort<char>> TypeChar;
typedef Types<BubbleSort<double>, InsertionSort<double>, MergeSort<double>, QuickSort<double>> TypeDouble;
typedef Types<BubbleSort<int>, InsertionSort<int>, MergeSort<int>, QuickSort<int>> TypeInt;
typedef Types<BubbleSort<float>, InsertionSort<float>, MergeSort<float>, QuickSort<float>> TypeFloat;


REGISTER_TYPED_TEST_SUITE_P(SortingTestInt, sort_int_1, sort_int_2, sort_int_3, sort_int_4, sort_int_5);
INSTANTIATE_TYPED_TEST_SUITE_P(SortingInt, SortingTestInt, TypeInt);

REGISTER_TYPED_TEST_SUITE_P(SortingTestDouble, sort_double_1);
INSTANTIATE_TYPED_TEST_SUITE_P(SortingDouble, SortingTestDouble, TypeDouble);

REGISTER_TYPED_TEST_SUITE_P(SortingTestFloat, sort_float_1);
INSTANTIATE_TYPED_TEST_SUITE_P(SortingFloat, SortingTestFloat, TypeFloat);

REGISTER_TYPED_TEST_SUITE_P(SortingTestChar, sort_char_1);
INSTANTIATE_TYPED_TEST_SUITE_P(SortingChar, SortingTestChar, TypeChar);