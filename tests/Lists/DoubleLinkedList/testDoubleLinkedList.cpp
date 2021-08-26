#include "gtest/gtest.h"
#include "DoubleLinkedList/List.h"

TEST(DoubleLinkedList, list_int_1) {
    DoubleLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.addItemFront(5);
    list.addItemBack(6);
    list.addItemFront(7);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.getVector(), std::vector<int>({7, 5, 6}));

    list.removeItem(6);
    EXPECT_EQ(list.getSize(), 2);
    list.removeItem(5);
    EXPECT_EQ(list.getSize(), 1);
    list.removeItem(7);
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getVector(), std::vector<int>());
}


TEST(DoubleLinkedList, list_int_2) {
    DoubleLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.addItemBack(6);
    list.addItemFront(7);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.getVector(), std::vector<int>({7, 6}));

    list.removeItem(7);
    EXPECT_EQ(list.getSize(), 1);
    list.removeItem(6);
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getVector(), std::vector<int>());
}

TEST(DoubleLinkedList, list_int_3) {
    DoubleLinkedList<int> list;
    list.removeItem(5);
    EXPECT_TRUE(list.isEmpty());

    list.addItemBack(6);
    list.addItemFront(7);
    list.removeItem(5);
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.getVector(), std::vector<int>({7, 6}));
}

TEST(DoubleLinkedList, printing) {
    DoubleLinkedList<int> list;
    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[]\n");

    list.addItemFront(4);
    list.addItemFront(3);
    list.addItemBack(7);
    list.addItemBack(9);
    testing::internal::CaptureStdout();
    list.printList();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[3, 4, 7, 9]\n");

    testing::internal::CaptureStdout();
    list.printReverseList();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[9, 7, 4, 3]\n");
}

TEST(DoubleLinkedList, set_get_values) {
    DoubleLinkedList<int> list;

    list.addItemFront(4);
    list.addItemFront(5);
    list.addItemBack(12);
    EXPECT_EQ(list.getFirstItem()->getValue(), 5);
    list.getFirstItem()->setValue(100);
    EXPECT_EQ(list.getFirstItem()->getValue(), 100);
    EXPECT_EQ(list.getLastItem()->getValue(), 12);
}