#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <cassert>
#include "AbstractSort/AbstractSort.h"
#include "BubbleSort/BubbleSort.h"
#include "InsertionSort/InsertionSort.h"
#include "QuickSort/QuickSort.h"

void readVectorFromFile(std::vector<int> &vec, std::string &fileName) {
    std::ifstream file(fileName);
    std::string s;
    if (file.is_open()) {
        getline(file, s);
        std::stringstream ss(s);
        std::string numberString;
        while (getline(ss, numberString, ';')) {
            vec.push_back(std::stoi(numberString));
        }
        file.close();
    } else {
        std::cerr << "Could not find file!" << std::endl;
    }
}

void runSort(AbstractSort<int> *abstract_sort, std::string algorithm_name) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    abstract_sort->sort();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << algorithm_name << " runtime: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " [ms]" << std::endl;
}

int main() {
    std::vector<int> vec;

    std::string fileName = "files/numbers10000.csv";
    readVectorFromFile(vec, fileName);

    BubbleSort<int> bubble_sort(vec);
    InsertionSort<int> insertion_sort(vec);
    QuickSort<int> quick_sort(vec);

    runSort(&bubble_sort, "BubbleSort");
    runSort(&insertion_sort, "InsertionSort");
    runSort(&quick_sort, "QuickSort");

    assert(bubble_sort.isSorted());
    assert(insertion_sort.isSorted());
    assert(quick_sort.isSorted());

    return 0;
}
