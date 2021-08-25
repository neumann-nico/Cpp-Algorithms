#include <iostream>
#include <set>

const int N = 9;

class SudokuSolver{
private:
    bool checkHorizontally(int sudoku[N][N], int &countZeros);
    bool checkVertically(int sudoku[N][N], int &countZeros);
    bool checkBlock(int sudoku[N][N], int start_x, int start_y, int &countZeros);
    bool checkBlocks(int sudoku[N][N], int &countZeros);
    void getNextFreePosition(int sudoku[N][N], int &row, int &column);
public:
    bool isValid(int sudoku[N][N], int &countZeros);
    bool isSolved(int sudoku[N][N]);
    void readSudoku(int sudoku[N][N]);
    void printSudoku(int sudoku[N][N]);
    bool solveSudoku(int sudoku[N][N]);
};

