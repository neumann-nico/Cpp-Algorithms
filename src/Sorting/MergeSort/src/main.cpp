#include "MergeSort/MergeSort.h"

int main() {
    std::vector<int> vec = {0, 14, 3, 7, 5, 10, 6, 2, 8};

    MergeSort<int> merge_sort(vec);
    merge_sort.printVector();
    merge_sort.sort();
    merge_sort.printVector();

    return 0;
}
