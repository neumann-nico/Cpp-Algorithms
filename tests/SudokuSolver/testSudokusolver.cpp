#include "gtest/gtest.h"
#include "SudokuSolver/SudokuSolver.h"

TEST(SudokuSolver, solvable1) {
    SudokuSolver sudoku_solver;
    EXPECT_FALSE(sudoku_solver.isSolved());

    std::vector<std::vector<int>> sudoku = {
            {0, 0, 3, 0, 2, 0, 6, 0, 0},
            {9, 0, 0, 3, 0, 5, 0, 0, 1},
            {0, 0, 1, 8, 0, 6, 4, 0, 0},
            {0, 0, 8, 1, 0, 2, 9, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 8},
            {0, 0, 6, 7, 0, 8, 2, 0, 0},
            {0, 0, 2, 6, 0, 9, 5, 0, 0},
            {8, 0, 0, 2, 0, 3, 0, 0, 9},
            {0, 0, 5, 0, 1, 0, 3, 0, 0}
    };
    sudoku_solver.setSudoku(sudoku);
    EXPECT_FALSE(sudoku_solver.isSolved());

    sudoku_solver.solveSudoku();
    EXPECT_TRUE(sudoku_solver.isSolved());
}

TEST(SudokuSolver, solvable2) {
    SudokuSolver sudoku_solver;
    EXPECT_FALSE(sudoku_solver.isSolved());

    std::vector<std::vector<int>> sudoku = {
            {2, 0, 0, 0, 8, 0, 3, 0, 0},
            {0, 6, 0, 0, 7, 0, 0, 8, 4},
            {0, 3, 0, 5, 0, 0, 2, 0, 9},
            {0, 0, 0, 1, 0, 5, 4, 0, 8},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 2, 7, 0, 6, 0, 0, 0},
            {3, 0, 1, 0, 0, 7, 0, 4, 0},
            {7, 2, 0, 0, 4, 0, 0, 6, 0},
            {0, 0, 4, 0, 1, 0, 0, 0, 3}
    };
    sudoku_solver.setSudoku(sudoku);
    EXPECT_FALSE(sudoku_solver.isSolved());

    sudoku_solver.solveSudoku();
    EXPECT_TRUE(sudoku_solver.isSolved());
}

TEST(SudokuSolver, solvable3) {
    SudokuSolver sudoku_solver;
    EXPECT_FALSE(sudoku_solver.isSolved());

    sudoku_solver.solveSudoku();
    EXPECT_TRUE(sudoku_solver.isSolved());
}

TEST(SudokuSolver, not_solvable1) {
    SudokuSolver sudoku_solver;
    EXPECT_FALSE(sudoku_solver.isSolved());

    std::vector<std::vector<int>> sudoku = {
            {0, 0, 3, 0, 2, 0, 6, 0, 0},
            {9, 0, 0, 3, 0, 5, 0, 0, 1},
            {0, 0, 1, 8, 0, 6, 4, 0, 0},
            {0, 0, 8, 1, 0, 2, 9, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 8},
            {0, 0, 6, 7, 0, 8, 2, 0, 0},
            {0, 0, 2, 6, 0, 9, 5, 0, 0},
            {8, 0, 0, 2, 0, 3, 0, 0, 9},
            {0, 0, 5, 0, 1, 0, 3, 0, 9}
    };
    sudoku_solver.setSudoku(sudoku);
    EXPECT_FALSE(sudoku_solver.isSolved());

    sudoku_solver.solveSudoku();
    EXPECT_FALSE(sudoku_solver.isSolved());
}


TEST(SudokuSolver, not_solvable2) {
    SudokuSolver sudoku_solver;
    EXPECT_FALSE(sudoku_solver.isSolved());

    std::vector<std::vector<int>> sudoku = {
            {0, 0, 3, 0, 2, 0, 6, 0, 0},
            {9, 0, 0, 3, 0, 5, 0, 0, 1},
            {0, 0, 1, 8, 1, 6, 4, 0, 0},
            {0, 0, 8, 1, 0, 2, 9, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 8},
            {0, 0, 6, 7, 0, 8, 2, 0, 0},
            {0, 0, 2, 6, 0, 9, 5, 0, 0},
            {8, 0, 0, 2, 0, 3, 0, 0, 9},
            {0, 0, 5, 0, 1, 0, 3, 0, 9}
    };
    sudoku_solver.setSudoku(sudoku);
    EXPECT_FALSE(sudoku_solver.isSolved());

    sudoku_solver.solveSudoku();
    EXPECT_FALSE(sudoku_solver.isSolved());
}