#include "InsertionSort/InsertionSort.h"

int main() {
    std::vector<int> vec = {0, 14, 3, 7, 2, 6};

    InsertionSort<int> insertion_sort(vec);
    insertion_sort.printVector();
    insertion_sort.sort();
    insertion_sort.printVector();

    return 0;
}
