#include <iostream>
#include <set>
#include "SudokuSolver/SudokuSolver.h"


void SudokuSolver::readSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::getline(std::cin, s);
        for (int j = 0; j < s.length(); ++j) {
            sudoku[i][j] = s.at(j) - '0';
        }
    }
}

void SudokuSolver::printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << sudoku[i][j];
        }
        std::cout << std::endl;
    }
}

bool SudokuSolver::checkHorizontally(int sudoku[N][N], int &countZeros) {
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

bool SudokuSolver::checkVertically(int sudoku[N][N], int &countZeros) {
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

bool SudokuSolver::checkBlock(int sudoku[N][N], int start_x, int start_y, int &countZeros) {
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

bool SudokuSolver::checkBlocks(int sudoku[N][N], int &countZeros) {
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            if (!checkBlock(sudoku, i, j, countZeros)) {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::isValid(int sudoku[N][N], int &countZeros) {
    return checkHorizontally(sudoku, countZeros) && checkVertically(sudoku, countZeros)
           && checkBlocks(sudoku, countZeros);
}

bool SudokuSolver::isSolved(int sudoku[N][N]) {
    int countZeros = 0;
    return isValid(sudoku, countZeros) && countZeros == 0;
}

void SudokuSolver::getNextFreePosition(int sudoku[N][N], int &row, int &column) {
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

bool SudokuSolver::solveSudoku(int sudoku[N][N]) {
    if (isSolved(sudoku)) return true;

    int i, j;
    getNextFreePosition(sudoku, i, j);
    for (int k = 1; k <= N; ++k) {
        sudoku[i][j] = k;
        int countZeros = 0;
        if (isValid(sudoku, countZeros)) {
            if (solveSudoku(sudoku))
                return true;
        }
        sudoku[i][j] = 0;
    }
    return false;
}
