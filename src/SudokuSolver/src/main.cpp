#include <iostream>
#include <set>
#include "SudokuSolver.cpp"

int main() {
    const int N = 9;
    int sudoku[N][N] = {0};
    std::cout << "Insert your sudoku here:" << std::endl;
    SudokuSolver sudoku_solver;
    sudoku_solver.readSudoku(sudoku);
    
    if (sudoku_solver.solveSudoku(sudoku)) {
        sudoku_solver.printSudoku(sudoku);
    } else {
        std::cout << "No solution found!" << std::endl;
    }

    return 0;
}
