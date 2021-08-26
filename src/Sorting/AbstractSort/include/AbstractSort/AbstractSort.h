#pragma once

#include <iostream>
#include <vector>

template<typename T>
class AbstractSort {
public:
    explicit AbstractSort(std::vector<T> &vec);

    bool isSorted();

    virtual void sort() = 0;

    void printVector();

    void setVector(std::vector<T> &vec);

    std::vector<T> &getVector();

protected:
    std::vector<T> vec;
};

