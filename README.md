# Cpp-Algorithms [![Build Status](https://app.travis-ci.com/neumann-nico/Cpp-Algorithms.svg?token=sWXK3xsuNP7enLJyxsxr&branch=main)](https://app.travis-ci.com/neumann-nico/Cpp-Algorithms) [![codecov](https://codecov.io/gh/neumann-nico/Cpp-Algorithms/branch/main/graph/badge.svg?token=190ZKI00Z3)](https://codecov.io/gh/neumann-nico/Cpp-Algorithms)

## About
This project contains a collection of C++ algorithms.
It is divided into different topics like data structures for lists and graphs.
Various algorithms are implemented on the data structures.
As build system CMake is used and C++17.

Currently, the following projects are implemented:

Backtracking
* SudokuSolver
  * readSudoku (Commandline, File), isValid, isSolved, solveSudoku, printSudoku

DoubleLinkedList
  * addItemFront, addItemBack, removeItem, reverse, getSize, printList

Graph
  * operations: processGraphFromFile, get/set/delete Nodes/Edges
  * algorithms: DFS/BFS, prim, kruskal, nearestNeighbor, doubleTree, branchAndBound, dijkstra, mooreBellmanFord, edmondsKarp, cycleCanceling, successiveShortestPath

Sorting
  * BubbleSort, InsertionSort, MergeSort, QuickSort and a performance analysis of all sorting algorithms

As continuous integration, Travis CI is used which builds the projects and executes the given GoogleTest test cases.

## How to use
The project can be imported into CMake compatible IDE's like Clion or Qt.
The top-level CMakeLists.txt is automatically processed and the user is able to run the projects or the test cases.

Alternatively:

### Build
```bash
./build.bash
```

### Run
```bash
cd build
./src/SudokuSolver/SudokuSolver_run # as an example
```

### Test
```bash
cd build
ctest
```
