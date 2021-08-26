#pragma once

#include "AbstractSort/AbstractSort.h"

template<typename T>
class InsertionSort : public AbstractSort<T> {
public:
    explicit InsertionSort(std::vector<T> &vec);

    void sort() override;
};

