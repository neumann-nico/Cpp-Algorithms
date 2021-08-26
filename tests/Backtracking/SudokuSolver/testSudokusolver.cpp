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

TEST(SudokuSolver, print) {
    SudokuSolver sudoku_solver;

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

    testing::internal::CaptureStdout();
    sudoku_solver.printSudoku();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0, 0, 3, 0, 2, 0, 6, 0, 0\n"
                      "9, 0, 0, 3, 0, 5, 0, 0, 1\n"
                      "0, 0, 1, 8, 0, 6, 4, 0, 0\n"
                      "0, 0, 8, 1, 0, 2, 9, 0, 0\n"
                      "7, 0, 0, 0, 0, 0, 0, 0, 8\n"
                      "0, 0, 6, 7, 0, 8, 2, 0, 0\n"
                      "0, 0, 2, 6, 0, 9, 5, 0, 0\n"
                      "8, 0, 0, 2, 0, 3, 0, 0, 9\n"
                      "0, 0, 5, 0, 1, 0, 3, 0, 0\n");

    sudoku_solver.solveSudoku();
    EXPECT_TRUE(sudoku_solver.isSolved());

    testing::internal::CaptureStdout();
    sudoku_solver.printSudoku();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4, 8, 3, 9, 2, 1, 6, 5, 7\n"
                      "9, 6, 7, 3, 4, 5, 8, 2, 1\n"
                      "2, 5, 1, 8, 7, 6, 4, 9, 3\n"
                      "5, 4, 8, 1, 3, 2, 9, 7, 6\n"
                      "7, 2, 9, 5, 6, 4, 1, 3, 8\n"
                      "1, 3, 6, 7, 9, 8, 2, 4, 5\n"
                      "3, 7, 2, 6, 8, 9, 5, 1, 4\n"
                      "8, 1, 4, 2, 5, 3, 7, 6, 9\n"
                      "6, 9, 5, 4, 1, 7, 3, 8, 2\n");
}