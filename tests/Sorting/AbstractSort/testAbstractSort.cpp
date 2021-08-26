#include "gtest/gtest.h"
#include "AbstractSort/AbstractSort.h"

template <typename T>
class AbstractSortTest : public AbstractSort<int>{
public:
    explicit AbstractSortTest(std::vector<T> &vec) : AbstractSort(vec){};
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

template class AbstractSortTest<int>;