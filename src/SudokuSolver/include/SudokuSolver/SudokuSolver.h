#include <iostream>
#include <vector>
#include <set>

class SudokuSolver {
public:
    explicit SudokuSolver(int fieldSize = 9);

    bool isValid(int &countZeros);

    bool isSolved();

    void readSudokuFromCommandline();

    void setSudoku(std::vector<std::vector<int>> &sudoku);

    void printSudoku();

    bool solveSudoku();

private:
    bool checkHorizontally(int &countZeros);

    bool checkVertically(int &countZeros);

    bool checkBlock(int start_x, int start_y, int &countZeros);

    bool checkBlocks(int &countZeros);

    void getNextFreePosition(int &row, int &column);

    std::vector<std::vector<int>> sudoku;
    const int N;
};

