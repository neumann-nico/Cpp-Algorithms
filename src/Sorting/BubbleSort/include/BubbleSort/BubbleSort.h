#include "AbstractSort/AbstractSort.h"

template <typename T>
class BubbleSort : public AbstractSort<T>{
public:
    explicit BubbleSort(std::vector<T> &vec);

    void sort() override;
};

