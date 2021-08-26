#include "gtest/gtest.h"
#include "AbstractSort/AbstractSort.h"

template<typename T>
class AbstractSortTest : public AbstractSort<T> {
public:
    explicit AbstractSortTest(std::vector<T> &vec) : AbstractSort<T>(vec) {};

    void sort() override {};
};


TEST(AbstractSort, set_get_int) {
    std::vector<int> vec = {0, 15, 41, 14, 24};

    AbstractSortTest<int> sorter(vec);
    EXPECT_EQ(sorter.getVector(), vec);
    EXPECT_FALSE(sorter.isSorted());

    std::vector<int> vec2 = {0, 41, 4, 4, 34};
    sorter.setVector(vec2);
    EXPECT_EQ(sorter.getVector(), vec2);
    EXPECT_FALSE(sorter.isSorted());
}

TEST(AbstractSort, print1) {
    std::vector<double> vec;
    AbstractSortTest<double> sorter(vec);

    testing::internal::CaptureStdout();
    sorter.printVector();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[]\n");
}

TEST(AbstractSort, print2) {
    std::vector<char> vec = {'a', 'd', 'f', 'e'};
    AbstractSortTest<char> sorter(vec);

    testing::internal::CaptureStdout();
    sorter.printVector();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[a, d, f, e]\n");
}

template
class AbstractSortTest<int>;

template
class AbstractSortTest<char>;

template
class AbstractSortTest<double>;