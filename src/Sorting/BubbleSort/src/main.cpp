#include <iostream>
#include "BubbleSort/BubbleSort.h"

int main() {
    std::vector<int> vec = {0, 14, 3, 7};

    BubbleSort<int> bubble_sort(vec);
    bubble_sort.printVector();
    bubble_sort.sort();
    bubble_sort.printVector();

    return 0;
}
