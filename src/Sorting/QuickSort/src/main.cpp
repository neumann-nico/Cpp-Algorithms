#include "QuickSort/QuickSort.h"

int main() {
    std::vector<int> vec = {0, 14, 3, 7, 5, 10, 6, 2, 8};

    QuickSort<int> quick_sort(vec);
    quick_sort.printVector();
    quick_sort.sort();
    quick_sort.printVector();

    return 0;
}
