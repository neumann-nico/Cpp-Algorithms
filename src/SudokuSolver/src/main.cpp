#include <iostream>
#include "SudokuSolver/SudokuSolver.h"

int main() {
    int fieldSize = 9;
    std::cout << "Insert your sudoku here:" << std::endl;
    SudokuSolver sudoku_solver(fieldSize);
    sudoku_solver.readSudokuFromCommandline();

    if (sudoku_solver.solveSudoku()) {
        sudoku_solver.printSudoku();
    } else {
        std::cout << "No solution found!" << std::endl;
    }

    return 0;
}
