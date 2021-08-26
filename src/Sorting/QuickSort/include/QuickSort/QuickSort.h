#pragma once

#include "AbstractSort/AbstractSort.h"

template<typename T>
class QuickSort : public AbstractSort<T> {
public:
    explicit QuickSort(std::vector<T> &vec);

    void sort() override;
private:
    void quickSort(int low, int high);
    int partition(int low, int high);
};
