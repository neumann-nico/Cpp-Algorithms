#include "gtest/gtest.h"
#include "DoubleLinkedList/List.h"

TEST(DoubleLinkedList, list_int_1) {
    DoubleLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.addItemBack(5);
    list.addItemBack(6);
    list.addItemFront(7);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.getVector(), std::vector<int>({7,5,6}));

    list.removeItem(6);
    EXPECT_EQ(list.getSize(), 2);
    list.removeItem(5);
    EXPECT_EQ(list.getSize(), 1);
    list.removeItem(7);
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getVector(), std::vector<int>());
}
