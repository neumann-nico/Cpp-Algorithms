#include <cassert>
#include "SudokuSolver/SudokuSolver.h"

SudokuSolver::SudokuSolver(int fieldSize) : N(fieldSize) {
    this->sudoku = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
}


void SudokuSolver::readSudokuFromCommandline() {
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::getline(std::cin, s);
        for (int j = 0; j < s.length(); ++j) {
            sudoku[i][j] = s.at(j) - '0';
        }
    }
}

void SudokuSolver::printSudoku() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << sudoku[i][j];
            if (j < N-1){
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

bool SudokuSolver::checkHorizontally(int &countZeros) {
    for (int i = 0; i < N; ++i) {
        std::set<int> row_set;
        for (int j = 0; j < N; ++j) {
            if (sudoku[i][j] == 0) {
                countZeros++;
                continue;
            }
            if (row_set.find(sudoku[i][j]) != row_set.end())
                return false;
            row_set.insert(sudoku[i][j]);
        }
    }
    return true;
}

bool SudokuSolver::checkVertically(int &countZeros) {
    for (int i = 0; i < N; ++i) {
        // every row should be unique or 0
        std::set<int> row_set;
        for (int j = 0; j < N; ++j) {
            if (sudoku[j][i] == 0) {
                countZeros++;
                continue;
            }
            if (row_set.find(sudoku[j][i]) != row_set.end())
                return false;
            row_set.insert(sudoku[j][i]);
        }
    }
    return true;
}

bool SudokuSolver::checkBlock(int start_x, int start_y, int &countZeros) {
    std::set<int> row_set;
    for (int i = start_x; i < 3; ++i) {
        for (int j = start_y; j < 3; ++j) {
            if (sudoku[i][j] == 0) {
                countZeros++;
                continue;
            }
            if (row_set.find(sudoku[i][j]) != row_set.end())
                return false;
            row_set.insert(sudoku[i][j]);
        }
    }
    return true;
}

bool SudokuSolver::checkBlocks(int &countZeros) {
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            if (!checkBlock(i, j, countZeros)) {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::isValid(int &countZeros) {
    return checkHorizontally(countZeros) && checkVertically(countZeros) && checkBlocks(countZeros);
}

bool SudokuSolver::isSolved() {
    int countZeros = 0;
    return isValid(countZeros) && countZeros == 0;
}

void SudokuSolver::getNextFreePosition(int &row, int &column) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (sudoku[i][j] == 0) {
                row = i;
                column = j;
                return;
            }
        }
    }
}

bool SudokuSolver::solveSudoku() {
    if (isSolved()) return true;

    int i, j;
    getNextFreePosition(i, j);
    for (int k = 1; k <= N; ++k) {
        sudoku[i][j] = k;
        int countZeros = 0;
        if (isValid(countZeros)) {
            if (solveSudoku())
                return true;
        }
        sudoku[i][j] = 0;
    }
    return false;
}

void SudokuSolver::setSudoku(std::vector<std::vector<int>> &sudoku) {
    assert(this->sudoku.size() == sudoku.size());
    this->sudoku = sudoku;
}
