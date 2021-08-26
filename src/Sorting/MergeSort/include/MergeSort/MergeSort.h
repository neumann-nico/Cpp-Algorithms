#pragma once

#include "AbstractSort/AbstractSort.h"

template<typename T>
class MergeSort : public AbstractSort<T> {
public:
    explicit MergeSort(std::vector<T> &vec);

    void sort() override;

private:
    void mergeSort(int low, int high);

    void merge(int low, int middle, int high);
};
