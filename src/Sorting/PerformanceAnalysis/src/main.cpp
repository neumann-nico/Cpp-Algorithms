#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <cassert>
#include "AbstractSort/AbstractSort.h"
#include "MergeSort/MergeSort.h"
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

void runAnalysis(std::vector<int> &vec) {
    BubbleSort<int> bubble_sort(vec);
    InsertionSort<int> insertion_sort(vec);
    MergeSort<int> merge_sort(vec);
    QuickSort<int> quick_sort(vec);
    std::vector<std::pair<AbstractSort<int> *, std::string>> sorterList = {
            {&bubble_sort,    "BubbleSort"},
            {&insertion_sort, "InsertionSort"},
            {&merge_sort,     "MergeSort"},
            {&quick_sort,     "QuickSort"},
    };

    for (auto &pair: sorterList) {
        runSort(pair.first, pair.second);
        assert(pair.first->isSorted());
    }
}

int main() {
    std::string fileName = "files/numbers10000.csv";
    std::vector<int> vec;
    readVectorFromFile(vec, fileName);
    runAnalysis(vec);

    return 0;
}
